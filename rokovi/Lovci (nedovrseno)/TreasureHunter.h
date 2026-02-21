#ifndef TREASUREHUNTER_H
#define TREASUREHUNTER_H

#include <QString>
#include <QPair>
#include <QChar>

class TreasureHunter
{
public:
    TreasureHunter();
    void fromQVariant(const QVariant& variant);
    QString toQString() const;
    QPair<unsigned, unsigned> position() const;
    QChar get_first_letter_name() const;
    unsigned speed() const;
    void move(unsigned x, unsigned y);
    void add_coin();

private:
    QString m_name;
    unsigned m_speed;
    unsigned m_coins_found;
    QPair<unsigned, unsigned> m_position;
};

#endif // TREASUREHUNTER_H
