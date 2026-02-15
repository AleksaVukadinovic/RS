#include "cellthread.h"
#include "mainwindow.h"
#include "room.h"

CellThread::CellThread(int i, int j, QObject* parent) : QThread(parent), _i(i), _j(j) {}

void CellThread::run() {
    MainWindow *window = qobject_cast<MainWindow*>(parent());
    Room* room = window->get_room();

    double temp_diff = 0.0;
    temp_diff += room->get_temperature_diff_from_cell_above(_i, _j);
    temp_diff += room->get_temperature_diff_from_cell_below(_i, _j);
    temp_diff += room->get_temperature_diff_from_cell_left(_i, _j);
    temp_diff += room->get_temperature_diff_from_cell_right(_i, _j);

    room->update_new_temperature_for_cell(_i, _j, temp_diff);

    emit temperature_calculated(_i, _j);
}
