#pragma once

namespace polar {
    struct Point;
    struct Line;
}
namespace cartesian {
    struct Point;
    struct Line;

    struct Point
    {
        double x;
        double y;

        Point(double x, double y) : x(x), y(y) {}
        double distanceTo(const Line& line) const;
        double distanceTo(const Point& point) const;
        double distanceTo(const polar::Line& line) const;
        double distanceTo(const polar::Point& point) const;
        polar::Point toPolar() const;
    };

    struct Line
    {
        double a;
        double b;
        double c;

        Line(double slope, double intercept, double yFactor = -1) : a(slope), b(yFactor), c(intercept) {}
        double distanceTo(const Line& line) const;
        double distanceTo(const Point& point) const;
        double distanceTo(const polar::Line& line) const;
        double distanceTo(const polar::Point& point) const;
        polar::Line toPolar() const;
    };
}

namespace cartesian {
    struct Point;
    struct Line;
}
namespace polar {
    struct Point;
    struct Line;

    struct Point
    {
        double r;
        double theta;

        Point(double r, double theta) : r(r), theta(theta) {}
        double distanceTo(const Line& line) const;
        double distanceTo(const Point& point) const;
        double distanceTo(const cartesian::Line& line) const;
        double distanceTo(const cartesian::Point& point) const;
        cartesian::Point toCartesian() const;
    };

    struct Line
    {
        double rho;
        double phi;

        Line(double rho, double theta) : rho(rho), phi(theta) {}
        double distanceTo(const Line& line) const;
        double distanceTo(const Point& point) const;
        double distanceTo(const cartesian::Line& line) const;
        double distanceTo(const cartesian::Point& point) const;
        cartesian::Line toCartesian() const;
    };
}
