#include "VehicleWithWindows.hpp"
#include "Vehicle.hpp"
#include <cstdint>
#include <ostream>

VehicleWithWindows::VehicleWithWindows(uint8_t number_of_windows,
                                       uint8_t number_of_wheels,
                                       uint8_t number_of_seats)
    : Vehicle(number_of_wheels, number_of_seats),
    m_number_of_windows(number_of_windows) {}

uint8_t VehicleWithWindows::number_of_windows() const {
    return m_number_of_windows;
}

std::ostream &operator<<(std::ostream &out, const VehicleWithWindows &vsp)
{
    return out << vsp.type() << " " << vsp.number_of_seats() << " " << vsp.number_of_wheels() << " " << vsp.number_of_windows();
}
