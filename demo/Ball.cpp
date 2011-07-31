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

#include "Ball.h"

Ball::Ball(int px, int py, int sx, int sy, int r) {
	/*! \brief Initialize vectors via initialization list
	 */
	x = 0;
	radius = r;
	
	offset = vector2d(px, py);
	slope = vector2d(sx, sy);
	center = point2d(px, py);
}
Ball::~Ball() {
	/*! \brief Empty constructor.
	 */
}
int Ball::getRadius() {
	/*! \return radius
	 */
	return radius;
}
point2d Ball::getCenter() {
	/*! \return center
	 */
	return center;
}
void Ball::update() {
	/*! \brief Move the Ball.
	 *
	 * Incrementing x and updating the center position.
	 */
	x++;
	
	center.setX(offset.getX() + (x * slope.getX()));
	center.setY(offset.getY() + (x * slope.getY()));
}
void Ball::collision(vector2d vec) {
	slope.mirrorWith(vec);
	offset = vector2d(center.getX(), center.getY());
	x = 0;
}