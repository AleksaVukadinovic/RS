#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class Room;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Room* get_room();

private:
    Ui::MainWindow *ui;
    Room* room;

private slots:
    void on_start_reading();
    void on_temperature_calculated(int i, int j);

private:
    void populate_table_widget();
    void start_threads();
};
#endif // MAINWINDOW_H
