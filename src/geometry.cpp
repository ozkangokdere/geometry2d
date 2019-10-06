#include "geometry.h"
#include <math.h>

namespace cartesian {

double Point::distanceTo(const Line& line) const
{
     return line.distanceTo(*this);
}

double Point::distanceTo(const Point& point) const
{
    return sqrt((point.x - x) * (point.x - x) + (point.y - y) * (point.y - y));
}

double Point::distanceTo(const polar::Line& line) const
{
    return distanceTo(line.toCartesian());
}

double Point::distanceTo(const polar::Point& point) const
{
    return distanceTo(point.toCartesian());
}

polar::Point Point::toPolar() const
{
    double rho = sqrt(x * x + y * y);
    double theta = atan2(y, x);
    return polar::Point(rho, theta);
}

double Line::distanceTo(const Line& line) const
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
    if (line.a != a)
        return 0;
    else if (b != 0)
        return distanceTo(Point(0, line.c));
    else
        return abs(c - line.c);
#pragma GCC diagnostic pop;
}

double Line::distanceTo(const Point& point) const
{
    return abs(a * point.x + c + b * point.y) / sqrt(a * a + a * a + b * b);;
}

double Line::distanceTo(const polar::Line& line) const
{
    return distanceTo(line.toCartesian());
}

double Line::distanceTo(const polar::Point& point) const
{
    return distanceTo(point.toCartesian());
}

polar::Line Line::toPolar() const
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
    if (b != 0)
    {
        double rho = -c / sqrt(b * b + a * a);
        double theta = atan2(b, a);
        return polar::Line(rho, theta);
    }
    else
        return polar::Line(c, 0);
#pragma GCC diagnostic pop;
}

}

namespace polar {

double Point::distanceTo(const Line& line) const
{
    return line.distanceTo(*this);
}

double Point::distanceTo(const Point& point) const
{
    return sqrt(r * r + point.r * point.r - 2 * r * point.r * cos(theta - point.theta));
}

double Point::distanceTo(const cartesian::Line& line) const
{
    return line.distanceTo(*this);
}

double Point::distanceTo(const cartesian::Point& point) const
{
    return distanceTo(point.toPolar());
}

cartesian::Point Point::toCartesian() const
{
    return cartesian::Point(r * cos(theta), r * sin(theta));
}

double Line::distanceTo(const Line& line) const
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
    if (phi != line.phi)
        return 0;
    else
        return abs(rho-line.rho);
#pragma GCC diagnostic pop;
}

double Line::distanceTo(const Point& point) const
{
    cartesian::Point cPoint = point.toCartesian();
    cartesian::Line cLine = toCartesian();
    return cLine.distanceTo(cPoint);
}

double Line::distanceTo(const cartesian::Line& line) const
{
    return distanceTo(line.toPolar());
}

double Line::distanceTo(const cartesian::Point& point) const
{
    return distanceTo(point.toPolar());
}

cartesian::Line Line::toCartesian() const
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wfloat-equal"
    if (phi != 0)
        return cartesian::Line(-cos(phi)/sin(phi), rho/sin(phi));
    else
        return cartesian::Line(-1, rho, 0);
#pragma GCC diagnostic pop;
}

}
