#pragma once
#include <vector>
#include <ostream>
#include "Vehicle.hpp"

class VehiclePark
{
public:
    VehiclePark() = default;
    ~VehiclePark();

    VehiclePark(const VehiclePark &other);
    void add(Vehicle *vehicle);

private:
    friend std::ostream &operator<<(std::ostream &out, const VehiclePark &vp);
    std::vector<Vehicle *> m_vehicles;
};
