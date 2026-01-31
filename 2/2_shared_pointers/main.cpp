#include <string>
#include <iostream>
#include <memory> //std::shared_ptr<T>

struct Point
{
    double _x;
    double _y;

    Point(const double x = 0.0, const double y = 0.0) {
        _x = x;
        _y = y;
        std::cout << "Created point: " << to_string() << std::endl;
    }
    
    ~Point() {
        std::cout << "Destroyedd point: " << to_string() << std::endl;
    }

    std::string to_string() {
        return "(" + std::to_string(_x) + ", " + std::to_string(_y)+ ")";
    }
};

int main() {
    // Note. Shared pointer is not a pointer itself, but an object
    std::shared_ptr<Point> p1 = std::make_shared<Point>(-5.0, 5.0);
    auto p2 = p1;

    std::cout << "Number of pointers to point: " << p1.use_count() << std::endl;

    {
        auto p3 = p2;
        std::cout << p3->to_string() << std::endl;
        std::cout << "Number of pointers to point: " << p1.use_count() << std::endl;
    }
    std::cout << "Number of pointers to point: " << p1.use_count() << std::endl;
    return 0;
}

