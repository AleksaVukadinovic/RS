#ifndef TREASUREMAP_H
#define TREASUREMAP_H

#include <QVector>
#include <QVariant>
#include <QVariantMap>
#include <QPair>
#include <unordered_map>

class TreasureMap
{
public:
    TreasureMap();

    void fromQVariant(const QVariant& variant);
    QVector<QVector<QString>> get_display_map() const;
    QPair<unsigned, unsigned> get_map_size() const;
    unsigned get_number_of_coins() const;
    void set_game_speed(unsigned speed);
    unsigned game_speed() const;
    bool is_wall(unsigned x, unsigned y) const;
    bool contains_treasure(unsigned x, unsigned y) const;
    void remove_treasure(unsigned x, unsigned y);

private:
    enum class Tile {
        Clear,
        Wall,
        Treasure
    };

    const std::unordered_map<int, Tile> tile_mapping = {
        {0, Tile::Clear},
        {1, Tile::Wall},
        {2, Tile::Treasure}
    };

    const std::unordered_map<Tile, QString> display_mapping = {
        {Tile::Clear, ""},
        {Tile::Wall, "#"},
        {Tile::Treasure, "@"}
    };

    QVector<QVector<Tile>> m_board;
    unsigned m_rows;
    unsigned m_cols;
    unsigned m_coins = 0;
    unsigned m_game_speed;
};

#endif // TREASUREMAP_H
