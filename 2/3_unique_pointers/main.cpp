#include <iostream>
#include <memory>

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

std::unique_ptr<Point> f(std::unique_ptr<Point> p) {
    std::cout << p->to_string() << std::endl;
    return std::move(p);
}

int main() {

    {
        std::unique_ptr<Point> p1 = std::make_unique<Point>(1, -1);
        std::cout << "p1: " << p1->to_string() << std::endl;
        
        // auto p2 = p1; <- this doesn't work
        auto p2 = std::move(p1);
        std::cout << "p2: " << p2->to_string() << std::endl;

        if (p1.get() == nullptr)
            std::cout << "p1 is nullptr\n";
        else 
            std::cout << "p1 is not nullptr\n";

        p2 = f(std::move(p2));
        std::cout << p2->to_string() << std::endl;
    }

    return 0;
}