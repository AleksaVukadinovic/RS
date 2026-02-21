#ifndef HUNTERTHREAD_H
#define HUNTERTHREAD_H

#include <QThread>
#include <QVector>
#include <QString>
#include <QMap>
#include <QMutex>
#include <QMutexLocker>
#include <QRandomGenerator>
#include <QPair>

#include "TreasureHunter.h"
#include "TreasureMap.h"

class HunterThread : public QThread
{
    Q_OBJECT
public:
    explicit HunterThread(TreasureHunter* hunter, TreasureMap& map, QMutex* hunter_mutex, QMutex* map_mutex, double game_speed);

    void run() override;

signals:
    void hunter_moved();
    void thread_finished();

private:
    TreasureMap m_map;
    TreasureHunter* m_hunter;
    QMutex* m_map_mutex;
    QMutex* m_hunters_mutex;
    double m_game_speed;

    void move_random_direction();
    QVector<QPair<unsigned, unsigned>> get_possible_moves();
};

#endif // HUNTERTHREAD_H
