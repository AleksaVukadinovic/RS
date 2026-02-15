#include "Serializable.h"
#include <QVariant>

class CourseItem : public Serializable {
public:
    CourseItem();

    static int numberOfAttributes();
    static QString attributeName(int idx);

    QVariant operator[](int idx) const;

    void setData(int idx, const QVariant &value);

    QVariant toVariant() const override;
    void fromVariant(const QVariant &variant) override;

private:
    static const int NUMBER_OF_ATTRIBUTES = 2;

    QString m_name;
    unsigned m_espb;
};
