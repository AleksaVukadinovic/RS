#ifndef SOURCE_H
#define SOURCE_H

#include <QString>
#include <QVariant>

class Source
{
public:
    Source();

    void fromQVariant(const QVariant &variant);
    QString toQString() const;

    unsigned volume() const;
    void set_volume(unsigned volume);

private:
    QString m_name;
    unsigned m_volume;
};

#endif // SOURCE_H
