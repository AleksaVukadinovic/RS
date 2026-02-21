#include "HunterThread.h"

HunterThread::HunterThread(TreasureHunter *hunter, TreasureMap& map, QMutex* hunter_mutex, QMutex* map_mutex, double game_speed)
    : m_map(map), m_hunter(hunter), m_map_mutex(map_mutex), m_hunters_mutex(hunter_mutex), m_game_speed(game_speed)
{}

void HunterThread::run() {
    while (m_map.get_number_of_coins() != 0) {
        QThread::msleep(100 / (m_hunter->speed()/m_map.game_speed()) * 1000);
    }

    move_random_direction();
}

void HunterThread::move_random_direction() {
    QMutexLocker map_locker(m_map_mutex);
    QMutexLocker hunter_locker(m_hunters_mutex);

    if (m_map.get_number_of_coins() == 0) {
        emit thread_finished();
        return;
    }

    QVector<QPair<unsigned int, unsigned int>> possible_moves = get_possible_moves();

    if (possible_moves.isEmpty()) {
        return;
    }

    int random_index = QRandomGenerator::global()->bounded(possible_moves.size());
    QPair<unsigned int, unsigned int> new_pos = possible_moves[random_index];

    m_hunter->move(new_pos.first, new_pos.second);

    if (m_map.contains_treasure(new_pos.first, new_pos.second)) {
        m_map.remove_treasure(new_pos.first, new_pos.second);
        m_hunter->add_coin();
    }

    emit hunter_moved();
}

QVector<QPair<unsigned int, unsigned int>> HunterThread::get_possible_moves() {
    QVector<QPair<unsigned int, unsigned int>> possible_moves;

    QPair<unsigned, unsigned> current_pos = m_hunter->position();
    unsigned int r = current_pos.first;
    unsigned int c = current_pos.second;

    QPair<unsigned, unsigned> map_size = m_map.get_map_size();
    unsigned int max_rows = map_size.first;
    unsigned int max_cols = map_size.second;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < 4; ++i) {
        int next_r = static_cast<int>(r) + dr[i];
        int next_c = static_cast<int>(c) + dc[i];

        if (next_r >= 0 && next_r < static_cast<int>(max_rows) &&
            next_c >= 0 && next_c < static_cast<int>(max_cols)) {

            if (!m_map.is_wall(next_r, next_c)) {
                possible_moves.push_back({static_cast<unsigned>(next_r), static_cast<unsigned>(next_c)});
            }
        }
    }

    return possible_moves;
}
