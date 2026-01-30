#include <iostream>
#include <string>

struct Point
{
    double _x;
    double _y;

    // kada jedan argument ima podrazumevanu vrednost, moraju i ostali
    Point(const double x = 0.0, const double y = 0.0) {
        _x = x;
        _y = y;
    }
    
    std::string to_string() {
        return "(" + std::to_string(_x) + ", " + std::to_string(_y)+ ")";
    }
};

// q ne zna (i ne moze da zna) da li je p obrisano
void f() {
    Point *p = new Point();
    auto q = p;
    if (rand() % 2 < 1) {
        delete p;
    }
}

int main() {

    // Sve su na steku, automatski se oslobadjaju
    Point p1(2.5, 5.0);
    Point p2(-3.0);
    Point p3(); // nije poziv konstruktora, vec poziv funkcije sa 0 argumenatra koja vraca objekat tipa Point
    Point p4 = Point(); // sad je ovo vec poziv konstruktora
    Point p5{};
    Point p6 = Point{}; 

    std::cout << p1.to_string() << std::endl;

    // Hip
    Point* p = new Point(-2.5, 5.0);
    if (p != nullptr) {
        std::cout << p->to_string() << std::endl;
        delete p;
    }

    size_t number_of_points = 10u;
    Point *arr = new Point[number_of_points]; // da bi ovo moglo mora da postoji default konstruktor
    for (size_t i = 0u; i < number_of_points; i++)
        std::cout << (i+1) << " - " << arr[i].to_string() << "\n";
   
    delete[] arr;

    return 0;
}