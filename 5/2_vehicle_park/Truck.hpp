#pragma once
#include "Vehicle.hpp"
#include "VehicleWithWindows.hpp"
#include <cstdint>

class Truck : public VehicleWithWindows {
public:
    Truck(uint8_t number_of_windows = 3,
        uint8_t number_of_wheels  = 6,
        uint8_t number_of_seats   = 3);

    std::string type() const override;
    Vehicle* copy() const override;
};

std::ostream& operator<<(std::ostream& out, const Truck& a);
