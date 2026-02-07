#include "Car.hpp"
#include "Vehicle.hpp"
#include "VehicleWithWindows.hpp"
#include <ostream>

Car::Car(uint8_t number_of_windows,
         uint8_t number_of_wheels,
         uint8_t number_of_seats)
    :VehicleWithWindows(number_of_windows, number_of_wheels, number_of_seats) {}

std::string Car::type() const {
    return "Car";
}

Vehicle* Car::copy() const {
    return new Car(*this);
}

std::ostream &operator<<(std::ostream &out, const Car &a)
{
    return out << a.type() << " " << a.number_of_seats() << " " << a.number_of_wheels() << " " << a.number_of_windows();
}
