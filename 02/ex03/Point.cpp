#include "Point.hpp"

Point::Point(): _x(0), _y(0)
{
}

Point::Point(float const x, float const y): _x(x), _y(y)
{
}

Point::~Point()
{
}

Point::Point(const Point &other)
{
	this->operator=(other);
}

Point &Point::operator=(const Point &other)
{
	Point *new_point = new Point(other._x.toFloat(), other._y.toFloat());
	return *new_point;
}

Fixed Point::get_x() const
{
	return this->_x;
}

Fixed Point::get_y() const
{
	return this->_y;
}