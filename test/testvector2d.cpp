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
	std::cout << "\nRunning tests for the libvec2d::vector2d class:" << std::endl;
	libvec2d::point2d P(1, 1);
	libvec2d::point2d Q(4, 5);
	libvec2d::vector2d a(0, 2);
	libvec2d::vector2d b(P, Q);
	std::cout << "\tCreated vectors a = " << a.print() << "and b = " << b.print() << ".\n";
	std::cout << "\ta + b = " << (a + b).print() << ".\n";
	std::cout << "\ta - b = " << (a - b).print() << ".\n";
	std::cout << "\ta * b = " << (a * b) << ".\n";
	std::cout << "\t3 * b = " << (b * 3).print() << ".\n";
	a += b;
	std::cout << "\ta += b;\n\ta = " << a.print() << ".\n";
	a -= b;
	std::cout << "\ta -= b;\n\ta = " << a.print() << ".\n";
	b *= 2;
	std::cout << "\tb *= 2;\n\tb = " << b.print() << ".\n";
	b *= .5;
	std::cout << "\tb *= .5;\n\tb = " << b.print() << ".\n";
	std::cout << "\tLength of a = " << a.getLength() << ".\n";
	std::cout << "\tLength of b = " << b.getLength() << ".\n";
	a.makeUnit();
	std::cout << "\tMake a unit;\n\ta = " << a.print() << ".\n";
	a.makeNormal();
	std::cout << "\ta 90° rotated;\n\ta = " << a.print() << ".\n";
	b.makeNormal();
	std::cout << "\tb 90° rotated;\n\tb = " << b.print() << ".\n";
	a.flipVector();
	std::cout << "\ta flipped;\n\ta = " << a.print() << ".\n";
	b.mirrorWith(a);
	std::cout << "\tb mirrored at a;\n\tb = " << b.print() << ".\n";
	std::cout << "Done with testing libvec2d::vector2d." << std::endl;
	return 0;
}