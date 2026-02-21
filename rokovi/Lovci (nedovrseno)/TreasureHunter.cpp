#include "TreasureHunter.h"
#include <QVariant>
#include <QVariantMap>
#include <QRandomGenerator>

TreasureHunter::TreasureHunter() {}

void TreasureHunter::fromQVariant(const QVariant &variant) {
    auto map = variant.toMap();
    m_name = map.value("ime").toString();
    m_speed = map.value("brzina").toUInt();
    m_coins_found = 0;
    m_position = {map.value("red").toUInt(), map.value("kolona").toUInt()};
}

QString TreasureHunter::toQString() const {
    return m_name + ", brzina: " + QString::number(m_speed) + ", novcica: " + QString::number(m_coins_found);
}
QPair<unsigned, unsigned> TreasureHunter::position() const {
    return m_position;
}
QChar TreasureHunter::get_first_letter_name() const {
    return m_name[0];
}

unsigned TreasureHunter::speed() const {
    return m_speed;
}

void TreasureHunter::move(unsigned x, unsigned y) {
    m_position = {x, y};
}

void TreasureHunter::add_coin() {
    auto generator = QRandomGenerator::global();
    m_coins_found += generator->bounded(1, 6);
}
