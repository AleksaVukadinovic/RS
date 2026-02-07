#include "Bicycle.hpp"
#include "Vehicle.hpp"
#include <ostream>

Bicycle::Bicycle(const uint8_t number_of_wheels, const uint8_t number_of_seats)
                :Vehicle(number_of_wheels, number_of_seats) {}

std::string Bicycle::type() const {
    return "Bicycle";
}

Vehicle* Bicycle::copy() const {
    return new Bicycle(*this);
}

std::ostream &operator<<(std::ostream &out, const Bicycle &a)
{
    return out << a.type() << " " << a.number_of_seats() << " " << a.number_of_wheels();
}
