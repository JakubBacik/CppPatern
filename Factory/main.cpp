#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>

class Point{
    Point(float x, float y) : _x(x), _y(y){}

public:
    float _x, _y;

    static Point NewCartesian(float x, float y)
    {
        return {x, y};
    }

    static Point NewPolar(float r, float theta)
    {
        return {r*cos(theta), r*sin(theta)};
    }

    friend std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        os << "x: " << point._x << "y :" << point._y; 
        return os;
    }
};


int main()
{
    auto p = Point::NewPolar(5, M_PI_4);
    std::cout << p << std::endl;

    return 0;
}