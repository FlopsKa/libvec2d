#ifndef BALL_H
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