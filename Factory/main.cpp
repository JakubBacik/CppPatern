#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>

class Point{
    Point(float x, float y) : _x(x), _y(y){}
    float _x, _y;
public:
    friend std::ostream &operator<<(std::ostream &os, const Point &point)
    {
        os << "x: " << point._x << "y :" << point._y; 
        return os;
    }
    static PointFactory Factory;
private:
    class PointFactory
    {
        PointFactory(){}
    public:
        static Point NewCartesian(float x, float y)
        {
            return {x, y};
        }

        static Point NewPolar(float r, float theta)
        {
            return {r*cos(theta), r*sin(theta)};
        }
    };
};

int main()
{
    auto p = Point::PointFactory.NewCartesian(5, 6);
    std::cout << p << std::endl;

    return 0;
}