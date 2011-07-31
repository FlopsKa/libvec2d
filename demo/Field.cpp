/*
 *	libvec2d - Small and efficient two-dimensional vector library written in C++.
 *
 *	Copyright (C) 2011 Florian Kalinke
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <vector>
#include <iostream>

#include "Field.h"
#include "Ball.h"

Field::Field() : h_wall(1, 0), v_wall(0, 1) {
	/*! \brief Sets up the other classes via the init list and assigns some default values to the private members.
	 */
	SCREEN_WIDTH = 640;
	SCREEN_HEIGHT = 480;
	SCREEN_BPP = 32;
	FPS = 60;
	
	screen = NULL;
	stop = false;
}
Field::~Field() {
	/*! \brief Empty destructor.
	 */
}
bool Field::init() {
	/*! \brief Initialize SDL.
	 * \return true if successful.
	 */
	 
	// Init SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1)
		return false;
	
	// Set up the screen
	screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
	if (screen == NULL) {
		return false;
	}
	
	SDL_WM_SetCaption("libvec2d demo - http://github.com/FlopsKa/", NULL);
	
	return true;
}
void Field::run() {
	/*! \brief Main loop.
	 */
	Timer fps;
	
	srand(time(NULL));
	
	// Get some balls
	Ball center(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0, 0, 50);
	std::vector<Ball> myBalls;
	std::vector<Ball>::iterator it;
	
	for(int i = 0; i <= 20; i++) 
		myBalls.push_back(Ball(80, 80, rand() % 3 + 10, rand() % 3 + 10, 20));

	while(!stop) {
		fps.start();
		
		// Events
		// handle events
		while( SDL_PollEvent( &event ) ) {
			if( event.type == SDL_QUIT ) { 
				stop = true; 
			}
		}
		
		// Logic
		for(it = myBalls.begin(); it != myBalls.end(); ++it) {
			//std::cout << it->getCenter().print() << std::endl;
		
			// check for collisions between the ball and the walls
			if((it->getCenter().getX() + it->getRadius() >= SCREEN_WIDTH - 20)		// collision with the right wall
				|| (it->getCenter().getX() - it->getRadius() <= 0 + 20)) {			// collision with the left wall
				it->collision(v_wall);
			}
			if((it->getCenter().getY() + it->getRadius() >= SCREEN_HEIGHT - 20) 	// collision with lower wall
				|| (it->getCenter().getY() - it->getRadius() <= 0 + 20)) {			// collision with upper wall
				it->collision(h_wall);	
			}
			
			// check for collision with the center ball
			if(it->getCenter().getDistanceTo(center.getCenter()) <= it->getRadius() + center.getRadius()) {
				vector2d c(it->getCenter(), center.getCenter());
				c.makeNormal();
				it->collision(c);
			}
		}
		
		for(it = myBalls.begin(); it != myBalls.end(); ++it)
			it->update();
			
		// Output
		SDL_LockSurface(screen);
		// Clear the screen
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));
		for(it = myBalls.begin(); it < myBalls.end(); ++it)
			fill_circle(screen, it->getCenter(), it->getRadius(), 0xffffffff);
		fill_circle(screen, center.getCenter(), center.getRadius(), 0xff0000ff);
		
		SDL_FreeSurface(screen);
		        
		// Update screen
		if(SDL_Flip(screen) == -1) {
			exit(1);
		}
		
		
		// Cut the framerate
		if((fps.get_ticks() < (1000 / FPS)))
			SDL_Delay((1000 / FPS) - fps.get_ticks());
	}
}
void Field::quit() {
	/*! \brief Free memory and quit SDL.
	 */
	SDL_Quit();
}

void Field::fill_circle(SDL_Surface *surface, point2d pos, int radius, Uint32 pixel) {
	/*! \brief SDL_Surface 32-bit circle-fill algorithm without using trig.
	 *
	 * While I humbly call this "Celdecea's Method", odds are that the 
	 * procedure has already been documented somewhere long ago.  All of
	 * the circle-fill examples I came across utilized trig functions or
	 * scanning neighbor pixels.  This algorithm identifies the width of
	 * a semi-circle at each pixel height and draws a scan-line covering
	 * that width.  
	 *
	 * The code is not optimized but very fast, owing to the fact that it
	 * alters pixels in the provided surface directly rather than through
	 * function calls.
	 *
	 * WARNING:  This function does not lock surfaces before altering, so
	 * use SDL_LockSurface in any release situation.
	 *
	 * Function from http://www.gpwiki.org/index.php/SDL:Tutorials:Drawing_and_Filling_Circles#Drawing_a_filled_circle
	 *
	 * Altered to use point2d.
	 */
    // Note that there is more to altering the bitrate of this 
    // method than just changing this value.  See how pixels are
    // altered at the following web page for tips:
    //   http://www.libsdl.org/intro.en/usingvideo.html
    static const int BPP = 4;
 
    double r = (double)radius;
 
    for (double dy = 1; dy <= r; dy += 1.0)     {
        // This loop is unrolled a bit, only iterating through half of the
        // height of the circle.  The result is used to draw a scan line and
        // its mirror image below it.
 
        // The following formula has been simplified from our original.  We
        // are using half of the width of the circle because we are provided
        // with a center and we need left/right coordinates.
 
        double dx = floor(sqrt((2.0 * r * dy) - (dy * dy)));
        int x = pos.getX() - dx;
 
        // Grab a pointer to the left-most pixel for each half of the circle
        Uint8 *target_pixel_a = (Uint8 *)surface->pixels + ((int)(pos.getY() + r - dy)) * surface->pitch + x * BPP;
        Uint8 *target_pixel_b = (Uint8 *)surface->pixels + ((int)(pos.getY() - r + dy)) * surface->pitch + x * BPP;
 
        for (; x <= pos.getX() + dx; x++)         {
            *(Uint32 *)target_pixel_a = pixel;
            *(Uint32 *)target_pixel_b = pixel;
            target_pixel_a += BPP;
            target_pixel_b += BPP;
        }
    }
}