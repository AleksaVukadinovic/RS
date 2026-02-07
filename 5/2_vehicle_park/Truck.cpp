#include "Truck.hpp"
#include "Vehicle.hpp"
#include "VehicleWithWindows.hpp"
#include <ostream>

Truck::Truck(uint8_t number_of_windows,
         uint8_t number_of_wheels,
         uint8_t number_of_seats)
    :VehicleWithWindows(number_of_windows, number_of_wheels, number_of_seats) {}

std::string Truck::type() const {
    return "Truck";
}

Vehicle* Truck::copy() const {
    return new Truck(*this);
}

std::ostream &operator<<(std::ostream &out, const Truck &a)
{
    return out << a.type() << " " << a.number_of_seats() << " " << a.number_of_wheels() << " " << a.number_of_windows();
}
