#include "CourseItem.hpp"

CourseItem::CourseItem() : m_name(""), m_espb(0u) {}

int CourseItem::numberOfAttributes() {
    return CourseItem::NUMBER_OF_ATTRIBUTES;
}

QString CourseItem::attributeName(int idx) {

    switch (idx) {
        case 0:
            return "Course name";
        case 1:
            return "ESPB";

        default:
            return "";
    }
}

QVariant CourseItem::operator[](int idx) const {

    switch (idx) {
        case 0:
            return QVariant(m_name);
        case 1:
            return QVariant(m_espb);

        default:
            return QVariant();
    }
}

void CourseItem::setData(int idx, const QVariant &value) {

    switch (idx) {
        case 0:
            m_name = value.toString();
            break;
        case 1:
            bool parsed = false;
            auto parsedValue = value.toUInt(&parsed);
            if (parsed) {
                m_espb = parsedValue;
            }
            break;
    }
}

QVariant CourseItem::toVariant() const {
    QVariantMap map;
    map.insert("name", m_name);
    map.insert("espb", m_espb);
    return map;
}

void CourseItem::fromVariant(const QVariant &variant) {
    QVariantMap map = variant.toMap();
    m_name = map.value("name").toString();
    m_espb = map.value("espb").toUInt();
}
