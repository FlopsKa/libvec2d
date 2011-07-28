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

#include "libvec2d.h"

using namespace libvec2d;

point2d::point2d () {
	/*! \brief Default constructor, initializes both member variables to zero (0).
	 */
	_x = 0;
	_y = 0;
}
point2d::point2d (float x = 0, float y = 0) {
	/*!	\brief point2d contructor
	 *	\param x defaults to 0, saved in the private member _x.
	 *	\param y defaults to 0, saved in the private member _y.
	 */
	_x = x;
	_y = y;
}
point2d::~point2d () {
	/*! \brief Empty destructor.
	 */
}
float point2d::getX () const {
	/*!	\return _x
	 */
	return _x;
}
void point2d::setX (float x) {
	/*!	\brief Set _x.
	 */
	_x = x;
}

float point2d::getY () const {
	/*!	\return _y
	 */
	return _y;
}
void point2d::setY (float y) {
	/*!	\brief Set _y.
	 */
	_y = y;
}

float point2d::getDistanceTo (point2d p) const {
	/*!	\brief Computes the distance between two points.
	 *	This is especially useful to check for collisions between circular objects.
	 *	\param p The point to compute the distance with.
	 *	\return The distance.
	 */
	return std::sqrt ((std::pow (_x - p.getX(), 2)) + std::pow (_y - p.getY(), 2));
}

std::string point2d::print() {
	/*! \brief Prints the point to stdout.
	 */
	std::stringstream ss;
	ss << "(" << _x << "|" << _y << ")";
	return ss.str();
}