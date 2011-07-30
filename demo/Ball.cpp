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