#pragma once
#include <cstdint>
#include <string>

class Vehicle {
protected:
    uint8_t m_number_of_wheels;
    uint8_t m_number_of_seats;

    Vehicle(const uint8_t number_of_wheels, const uint8_t number_of_seats);
public:
    virtual ~Vehicle() = default;

    virtual std::string type() const = 0;
    virtual Vehicle* copy() const = 0;

    uint8_t number_of_wheels() const;
    uint8_t number_of_seats() const;
};
