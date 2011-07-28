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
 
#include <iostream>

#include "libvec2d.h"

int main (int args, char *argv[]) {
	std::cout << "\nRunning tests for the libvec2d::point2d class:" << std::endl;
	libvec2d::point2d O(0, 0);
	libvec2d::point2d P(1, 1);
	libvec2d::point2d Q(4, 5);
	std::cout << "\tCreated points O" << O.print() << ", P" << P.print() << "and Q" << Q.print() << ".\n";
	std::cout << "\tDistance from origin to P is " << O.getDistanceTo(P) << ". Shall be √2.\n";
	std::cout << "\tDistance from P to Q is " << P.getDistanceTo(Q) << ". Shall be 5.\n";
	std::cout << "Done with testing libvec2d::point2d." << std::endl;
	return 0;
}