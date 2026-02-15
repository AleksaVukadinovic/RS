#ifndef ROOM_H
#define ROOM_H

#include <QObject>
#include <QVector>

class Room : public QObject
{
    Q_OBJECT
public:
    explicit Room(int n, QObject *parent = nullptr);

    inline int size() const { return m_matrix.size(); }
    inline int cell_value(int i, int j) const { return m_matrix[i][j]; }
    double get_temperature_diff_from_cell_above(int i, int j) const;
    double get_temperature_diff_from_cell_below(int i, int j) const;
    double get_temperature_diff_from_cell_left(int i, int j) const;
    double get_temperature_diff_from_cell_right(int i, int j) const;
    void update_new_temperature_for_cell(int i, int j, double temp_diff);

private:
    QVector<QVector<double>> m_matrix;
    const double TEMP_COEFFICIENT = 0.1;

signals:
};

#endif // ROOM_H
