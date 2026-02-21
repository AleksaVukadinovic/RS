#include "source.h"

Source::Source() {}

void Source::fromQVariant(const QVariant &variant) {
    const auto map = variant.toMap();
    m_name = map.value("name").toString();
    m_volume = map.value("volume").toUInt();
}

QString Source::toQString() const {
    return m_name + " - " + (m_volume == 0 ? "Izvor je iscprljen" : QString::number(m_volume));
}

unsigned int Source::volume() const {
    return m_volume;
}

void Source::set_volume(unsigned int volume) {
    m_volume = volume;
}
