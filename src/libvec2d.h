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
 
#ifndef LIBVEC2D_H
#define LIBVEC2D_H

#include <cmath>
#include <sstream>
#include <string>

/*!	\brief Namespace is used for the whole library.
 */
namespace libvec2d {

/*!	\class point2d
 *	\brief This class is used to represent a point in a two-dimensional coordinate system.
 *
 *	In case it is called without passing arguments to the contructor it initializes itself to (0|0).
 */
class point2d {
	private:
	float _x;
	float _y;
	
	public:
	point2d ();
	point2d (float, float);		
	~point2d ();
	float getX () const;
	void setX (float);
	float getY () const;
	void setY (float);
	float getDistanceTo (point2d) const;
	std::string print();
};

/*!	\class vector2d
 *	\brief This class is used to represent a vector in a two-dimensional coordinate system.
 *
 *	The vector is stored in a tupel. There are methods to do some basic vector math like the scalar product, multiplying a vector and a scalar or adding / substracting other vectors.
 *	In case it is called without passing arguments to the contructor it initializes itself to (0|0).
 */
class vector2d {
	private:
	float _x;
	float _y;
	
	public:
	vector2d ();
	vector2d (float, float);
	vector2d (point2d, point2d);
	~vector2d ();
	float getX () const;
	void setX (float);
	float getY () const;
	void setY (float);
	vector2d operator + (vector2d) const;
	vector2d operator - (vector2d) const;
	float operator * (vector2d) const;
	vector2d operator * (float) const;
	vector2d operator += (vector2d);
	vector2d operator -= (vector2d);
	vector2d operator *= (float);
	float getLength ();
	void makeUnit ();
	void makeNormal ();
	void flipVector ();
	void mirrorWith(vector2d);
	std::string print() const;
};
} // end of namespace libvec2d

#endif // #define LIBVEC2D_H