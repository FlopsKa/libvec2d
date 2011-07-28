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

vector2d::vector2d (int x = 0, int y = 0) {
	/*!	\brief vector2d contructor
	 *	\param x defaults to 0, saved in the private member _x.
	 *	\param y defaults to 0, saved in the private member _y.
	 */
	_x = x;
	_y = y;
}
vector2d::vector2d (point2d p, point2d q) {
	/*!	\brief vector2d contructor, creates a vector from two points.
	 *
	 *	The vector faces from Point1 to Point2. 
	 *	\param p Point1
	 *	\param q Point2
	 */
	_x = q.getX() - p.getX();
	_y = q.getY() - p.getY();
}
vector2d::~vector2d () {
	/*! \brief Empty destructor.
	 */
};
float vector2d::getX () const {
	/*!	\return _x
	 */
	return _x;
}
void vector2d::setX (float x) {
	/*!	\brief Set _x.
	 */
	_x = x;
}

float vector2d::getY () const {
	/*!	\return _y
	 */
	return _y;
}
void vector2d::setY (float y) {
	/*!	\brief Set _y.
	 */
	_y = y;
}
vector2d vector2d::operator + (vector2d vec) const {
	/*!	\brief Adds the vector from the argument to this vector and returns the result.
	 *	\param vec Vector to add.
	 *	\return The sum.
	 */
	vector2d tmp(_x + vec.getX(), _y + vec.getY());
	return tmp;
}
vector2d vector2d::operator - (vector2d vec) const {
	/*!	\brief Substracts the vector from the argument from this vector and returns the result.
	 *	\param vec Vector to substract.
	 *	\return The difference.
	 */
	vector2d tmp(_x - vec.getX(), _y - vec.getY());
	return tmp;
}

float vector2d::operator * (vector2d vec) const {
	/*!	\brief Calculates the scalar product of the object it is called on and the vector in the argument and returns the result.
	 *	\param vec vector2d to multiply with.
	 *	\return The scalar product.
	 */
	return ((_x * vec.getX()) + (_y * vec.getY()));
}
vector2d vector2d::operator * (float scalar) const {
	/*!	\brief Multiplies the vector with the scalar from the argument and returns the resulting vector.
	 *	\param scalar Scalar to multiply with.
	 *	\return The product.
	 */
	vector2d tmp(_x * scalar, _y * scalar);
	return tmp;
}
vector2d vector2d::operator += (vector2d vec) {
	/*!	\brief Adds the vector in the argument and returns the sum.
	 *	\param vec The vektor2d to add.
	 *	\return The resulting vector2d.
	 */
	 _x += vec.getX();
	 _y += vec.getY();
	 
	 return *this;
}
vector2d vector2d::operator -= (vector2d vec) {
	/*!	\brief Substracts the vector in the argument and returns the result.
	 *	\param vec vektor2d to substract.
	 *
	 *	\return The resulting vector2d.
	 */
	 _x -= vec.getX();
	 _y -= vec.getY();
	 
	 return *this;
}
vector2d vector2d::operator *= (float scalar) {
	/*!	\brief Multiplies the object it is called up on with the scalar in the argument and returns the result.
	 *	\param scalar Scalar to multiply with.
	 *	\return The resulting vector2d.
	 */
	_x *= scalar;
	_y *= scalar;
	
	return *this;
}
float vector2d::getLength() {
	/*! \brief Returns the length of the vector.
	 */
	return std::sqrt (std::pow (_x, 2) + (std::pow (_y, 2)));
}
void vector2d::makeUnit () {
	/*! \brief Devides the vector by it's length so it has a unit length.
	 */
	if (getLength() == 0)
		return;		// This is needed because we can't devide by 0
	*this *= (1.0 / getLength());
}
void vector2d::makeNormal () {
	/*! \brief Flips the vector 90°.
	 */
	float tmp = _x;
	_x = _y;
	_y = tmp;
	_x *= (-1);
}
void vector2d::flipVector () {
	/*!	\brief Flips the vector so it points to the opposite direction.
	 */
	*this *= (-1);
}
void vector2d::mirrorWith(vector2d vec) {
	/*!	\brief Reflects the vector using a normal as mirror.
	 *	
	 *	The term reflection can also refer to the reflection of a ball, ray of light, etc. off a flat surface. As shown in the right diagram above, the reflection of a points x_1 off a wall with normal vector n satisfies x1' - x0 = v - 2 (v * n) * n. 
	 *	Source: http://mathworld.wolfram.com/Reflection.html
	 *	\param vec The vector which is used as mirror (n)
	 */
	vector2d tmp = vec;
	tmp.makeNormal();
	
	*this -= tmp * (*this * tmp) * 2;
}
std::string vector2d::print() const {
	/*! \brief Prints the vector to stdout.
	 */
	std::stringstream ss;
	ss << "[" << _x << ", " << _y << "]";
	return ss.str();
}
