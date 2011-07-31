#ifndef BALL_H
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

#define BALL_H

#include "libvec2d.h"

// Set the correct namespace
// This is important, else you would have to put libvec2d:: in front of every library stuff
using namespace libvec2d;

/*! \brief Used to represent the balls on the Field. The vector magic happens here.
 */
class Ball {
	private:
	/// Sets the radius of the ball
	int radius;
	
	/// Stores the center of the ball
	point2d center;
	
	/* The vector math
	 * The ball travels on a line which has the form
	 * g:x = r0 + x * u
	 * where r0 is the offset and u is the slope.
	 *
	 * To move the ball we need to increment x.
	 */
	vector2d offset;
	vector2d slope;
	int x;
	
	public:
	Ball(int, int, int, int, int);
	~Ball();
	int getRadius();
	point2d getCenter();
	void update();
	void collision(vector2d);
};

#endif // end of BALL_H