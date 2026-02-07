#include "Vehicle.hpp"
#include <ostream>

Vehicle::Vehicle(const uint8_t number_of_wheels, const uint8_t number_of_seats)
    : m_number_of_wheels(number_of_wheels), m_number_of_seats(number_of_seats) {}

uint8_t Vehicle::number_of_wheels() const {
    return m_number_of_wheels;
}
uint8_t Vehicle::number_of_seats() const {
    return m_number_of_seats;
}

std::ostream &operator<<(std::ostream &out, const Vehicle& v) {
    return out << v.type() << " " << v.number_of_seats() << " " << v.number_of_wheels();
}
