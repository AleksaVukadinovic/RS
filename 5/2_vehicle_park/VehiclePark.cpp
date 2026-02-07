#include "VehiclePark.hpp"

VehiclePark::VehiclePark(const VehiclePark &other)
{
    for (const auto v : other.m_vehicles)
        m_vehicles.push_back(v->copy());
}

VehiclePark::~VehiclePark()
{
    for (auto v : m_vehicles)
        delete v;
    m_vehicles.clear();
}

void VehiclePark::add(Vehicle *vehicle)
{
    m_vehicles.push_back(vehicle);
}

std::ostream &operator<<(std::ostream &out, const VehiclePark &vp)
{
    for (const auto v : vp.m_vehicles)
        out << v << ", ";
    return out;
}
