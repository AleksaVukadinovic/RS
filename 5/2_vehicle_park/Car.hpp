#pragma once
#include "Vehicle.hpp"
#include "VehicleWithWindows.hpp"
#include <cstdint>

class Car : public VehicleWithWindows {
public:
    Car(uint8_t number_of_windows = 6,
        uint8_t number_of_wheels  = 4,
        uint8_t number_of_seats   = 5);

    std::string type() const override;
    Vehicle* copy() const override;
};
