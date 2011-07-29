#ifndef FIELD_H
#define FIELD_H
#include <string>
#include <cmath>

#include "SDL.h"
#include "libvec2d.h"

using namespace libvec2d;

#include "Timer.h"

/*! \brief Abstract main game class.
 *
 * Instanciated in main.cpp and used to get the demo runnig. Sets up the SDL subsystem and contains the game loop.
 */
class Field {
	private:
	/// The width of the screen in pixels
	int SCREEN_WIDTH;
	
	/// The height of the screen in pixels
	int SCREEN_HEIGHT;
	
	/// Bits per point
	int SCREEN_BPP;
	
	/// Frames per second
	int FPS;
	
	/// The main surface which is used to get an image to the screen
	SDL_Surface *screen;
	
	// Event handling
	SDL_Event event;
	
	/// Used to handle the main loop and to quit the game
	bool stop;
	
	/// Used to bounce the ball of a vertical wall
	vector2d v_wall;
	
	/// Used to bounce the ball of a horizontal wall
	vector2d h_wall;
	
	public:
	Field();
	~Field();
	bool init();
	void run();
	void quit();
	
	// Some SDL specific stuff from http://lazyfoo.net
	void apply_surface(int, int, SDL_Surface*, SDL_Surface*);
	
	// Function to draw circles from http://www.gpwiki.org/index.php/SDL:Tutorials:Drawing_and_Filling_Circles
	void fill_circle(SDL_Surface*, point2d, int, Uint32);
};

#endif // end of FIELD_H
