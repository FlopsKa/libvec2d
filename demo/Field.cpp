#include "Field.h"
#include "Ball.h"

Field::Field() : h_wall(1, 0), v_wall(0, 1) {
	/*! \brief Sets up the other classes via the init list and assigns some default values to the private members.
	 */
	SCREEN_WIDTH = 640;
	SCREEN_HEIGHT = 480;
	SCREEN_BPP = 32;
	FPS = 30;
	
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
	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) {
		return false;
	}
	
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
	
	// Get a ball
	Ball myBall;
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
		myBall.update();
		
		// check for collisions between the ball and the walls
		if((myBall.getCenter().getX() + myBall.getRadius() >= SCREEN_WIDTH)		// collision with the right wall
			|| (myBall.getCenter().getX() - myBall.getRadius() <= 0)) {			// collision with the left wall
			myBall.collision(v_wall);
		}
		if((myBall.getCenter().getY() + myBall.getRadius() >= SCREEN_HEIGHT) 	// collision with lower wall
			|| (myBall.getCenter().getY() - myBall.getRadius() <= 0)) {			// collision with upper wall
			myBall.collision(h_wall);	
		}
		// Output
		SDL_LockSurface(screen);
		// Clear the screen
		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));
		fill_circle(screen, myBall.getCenter(), 20, 0xffffffff);
		
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