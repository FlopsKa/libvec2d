#include "Ball.h"

Ball::Ball() : offset(40, 40), slope(3, 3), center(40, 40) {
	/*! \brief Initialize vectors via initialization list
	 */
	x = 0;
	radius = 30;
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
	
	center.setX(offset.getX() + (x * slope.getX())); // works
	center.setY(offset.getY() + (x * slope.getY())); // gives segfault
}
void Ball::collision(vector2d vec) {
	slope.mirrorWith(vec);
	offset = vector2d(center.getX(), center.getY());
	x = 0;
}