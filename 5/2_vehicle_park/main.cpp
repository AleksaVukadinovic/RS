#include <iostream>
#include "Bicycle.hpp"
#include "VehicleWithWindows.hpp"
#include "Car.hpp"
#include "Truck.hpp"
#include "VehiclePark.hpp"

int main()
{
    std::cout << "Testiranje pojedinacnih klasa" << std::endl;
    const Car a;
    const Truck t;
    const Bicycle b;
    const VehicleWithWindows *v = new Truck();

    std::cout << a << std::endl;
    std::cout << t << std::endl;
    std::cout << b << std::endl;
    std::cout << *v << std::endl;

    std::cout << "Testiranje voznog parka" << std::endl;
    VehiclePark vp;

    vp.add(a.copy());
    vp.add(t.copy());
    vp.add(new Car());
    vp.add(new Bicycle(4, 2));

    std::cout << vp << std::endl;

    std::cout << "Testiranje pravljenja kopije voznog parka" << std::endl;
    auto vp2 = vp;

    vp2.add(new Truck());

    std::cout << vp2 << std::endl;
    std::cout << vp << std::endl;

    delete v;

    return 0;
}
