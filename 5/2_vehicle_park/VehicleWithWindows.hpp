#pragma once
#include "Vehicle.hpp"
#include <cstdint>

class VehicleWithWindows : public Vehicle {
protected:
    uint8_t m_number_of_windows;

public:
    VehicleWithWindows(uint8_t number_of_windows,
                       uint8_t number_of_wheels,
                       uint8_t number_of_seats);
    ~VehicleWithWindows() {}
    uint8_t number_of_windows() const;
};

std::ostream& operator<<(std::ostream& out, const VehicleWithWindows& a);
