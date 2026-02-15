#pragma once
#include "Serializer.hpp"

class JSONSerializer : public Serializer {
public:
    JSONSerializer();
    void save(const Serializable &serializable, const QString &filepath, const QString &rootName = "") override;
    void load(Serializable &serializable, const QString &filepath) override;
};
