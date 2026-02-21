#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QVector>
#include "TreasureHunter.h"
#include "TreasureMap.h"
#include <QMutex>
#include <QMutexLocker>
#include "HunterThread.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_load_data();
    void on_start_search();
    void on_game_speed_changed();
    void on_hunter_moved();

private:
    Ui::MainWindow *ui;
    TreasureMap m_map;
    QVector<TreasureHunter* > m_hunters;
    QMutex m_map_mutex;
    QMutex m_hunters_mutex;
    double m_game_speed = 1.0;
    bool m_can_start_search = false;

    void display_hunters();
    void display_map();
    void disable_controls();
    void start_threads();
};
#endif // MAINWINDOW_H
