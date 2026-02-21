#include "TreasureMap.h"

TreasureMap::TreasureMap() {}

void TreasureMap::fromQVariant(const QVariant &variant) {
    m_board.clear();

    const auto row_list = variant.toList();
    m_rows = row_list.size();

    for (size_t i{}; i < m_rows; ++i) {
        const auto row = row_list[i].toList();
        m_board.push_back(QList<Tile>());

        for (const auto &tile : row) {
            m_board[i].push_back(tile_mapping.at(tile.toInt()));
            if (tile_mapping.at(tile.toInt()) == Tile::Treasure)
                m_coins++;
        }
    }
    m_cols = m_board[0].size();
}
QVector<QVector<QString>> TreasureMap::get_display_map() const {
    QVector<QVector<QString>> display_map;
    display_map.resize(m_rows);
    for (size_t i{}; i < m_rows; ++i) {
        display_map[i].resize(m_cols);

        for (size_t j{}; j < m_cols; ++j) {
            display_map[i][j] = display_mapping.at(m_board[i][j]);
        }
    }
    return display_map;
}
QPair<unsigned, unsigned> TreasureMap::get_map_size() const {
    return {m_rows, m_cols};
}
unsigned TreasureMap::get_number_of_coins() const { return m_coins; }
void TreasureMap::set_game_speed(unsigned speed) { m_game_speed = speed; }
unsigned TreasureMap::game_speed() const { return m_game_speed; }
bool TreasureMap::is_wall(unsigned x, unsigned y) const {
    return m_board[x][y] == Tile::Wall;
}
bool TreasureMap::contains_treasure(unsigned x, unsigned y) const {
    return m_board[x][y] == Tile::Treasure;
}
void TreasureMap::remove_treasure(unsigned x, unsigned y) {
    if (m_board[x][y] == Tile::Treasure)
        m_board[x][y] = Tile::Clear;
}
