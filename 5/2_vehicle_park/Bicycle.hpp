#pragma once
#include "Vehicle.hpp"
#include <cstdint>

class Bicycle : public Vehicle {
public:
    Bicycle();
    Bicycle(const uint8_t number_of_wheels, const uint8_t number_of_seats);

    std::string type() const override;
    Vehicle* copy() const override;
};
