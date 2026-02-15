#include "room.h"
#include <QRandomGenerator>

Room::Room(int n, QObject *parent) : QObject{parent} {
    for (int i = 0; i < n; i++) {
        QVector<double> row;
        for (int j =0;j<n; j++) {
            const auto random_temp = QRandomGenerator::global()->bounded(15, 30);
            row.push_back(random_temp);
        }
        m_matrix.push_back(row);
    }
}

double Room::get_temperature_diff_from_cell_above(int i, int j) const
{
    if (i <= 0)
    {
        return 0.0;
    }
    return TEMP_COEFFICIENT * (m_matrix[i-1][j] - m_matrix[i][j]);
}

double Room::get_temperature_diff_from_cell_below(int i, int j) const
{
    if (i >= m_matrix.size() - 1)
    {
        return 0.0;
    }
    return TEMP_COEFFICIENT * (m_matrix[i+1][j] - m_matrix[i][j]);
}

double Room::get_temperature_diff_from_cell_left(int i, int j) const
{
    if (j <= 0)
    {
        return 0.0;
    }
    return TEMP_COEFFICIENT * (m_matrix[i][j-1] - m_matrix[i][j]);
}

double Room::get_temperature_diff_from_cell_right(int i, int j) const
{
    if (j >= m_matrix.size() - 1)
    {
        return 0.0;
    }
    return TEMP_COEFFICIENT * (m_matrix[i][j+1] - m_matrix[i][j]);
}

void Room::update_new_temperature_for_cell(int i, int j, double temp_diff)
{
    m_matrix[i][j] = temp_diff;
}
