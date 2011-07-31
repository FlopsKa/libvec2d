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

#ifndef FIELD_H
#define FIELD_H
#include <string>
#include <cmath>

#include "SDL/SDL.h"
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
