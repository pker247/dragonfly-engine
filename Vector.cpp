//
// Vector.cpp
//

// System includes
#include <math.h>

// Engine includes
#include "Vector.h"

namespace df {

Vector::Vector(float init_x, float init_y) {
	x = init_x;
	y = init_y;
}

Vector::Vector() {
	x = 0;
	y = 0;
}

void Vector::setX(float new_x) {
	x = new_x;
}

float Vector::getX() const {
	return x;
}

void Vector::setY(float new_y) {
	y = new_y;
}

float Vector::getY() const {
	return y;
}

void Vector::setXY(float new_x, float new_y) {
	x = new_x;
	y = new_y;
}

float Vector::getMagnitude() const {
	float mag = sqrt((x * x) + (y * y));
	return mag;
}

void Vector::normalize() {
	float length = getMagnitude();
	if (length > 0) {
		x = x / length;
		y = y / length;
	}
}

void Vector::scale(float s) {
	x = x * s;
	y = y * s;
}

Vector Vector::operator+(const Vector &other) const {
	Vector v;
	v.x = x + other.x;
	v.y = y + other.y;
	return v;
}

} // end namespace df