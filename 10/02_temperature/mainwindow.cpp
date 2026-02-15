#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "room.h"
#include "cellthread.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
    , room(nullptr)
{
    ui->setupUi(this);
    connect(ui->start_reading, &QPushButton::clicked, this, &MainWindow::on_start_reading);

}

MainWindow::~MainWindow()
{
    delete ui;
}

Room *MainWindow::get_room()
{
    return room;
}

void MainWindow::populate_table_widget() {
    const int size = room->size();

    ui->matrix->setRowCount(size);
    ui->matrix->setColumnCount(size);
    for (int i=0; i<size; i++) {
        for(int j = 0 ; j<size; j++) {
            const int cell_value = room->cell_value(i, j);
            auto table_item = new QTableWidgetItem(QString::number(cell_value));
            ui->matrix->setItem(i, j, table_item);
        }
    }
}

void MainWindow::start_threads() {
    const int size = room->size();

    for (int i=0; i<size; i++) {
        for(int j = 0 ; j<size; j++) {
            auto thread = new CellThread(i, j, this);
            connect(thread, &QThread::finished, thread, &QObject::deleteLater);
            connect(thread, &CellThread::temperature_calculated, this, &MainWindow::on_temperature_calculated);
            thread->start();
        }
    }
}

void MainWindow::on_start_reading() {
    const auto number_str = ui->rows_columns->text();
    bool parsed;
    const auto n = number_str.toInt(&parsed);
    if (!parsed || n<=0) {
        QMessageBox box;
        box.setText("Invalid input!");
        box.exec();
        return;
    }

    room = new Room(n, this); // We don't need to manually free room, it will be freed by MainWindow
    populate_table_widget();

    start_threads();
}

void MainWindow::on_temperature_calculated(int i, int j) {
    const double cell_value = room->cell_value(i, j);
    ui->matrix->item(i, j)->setText(QString::number(cell_value));

    // Wrong approach
    // auto table_item = new QTableWidgetItem(QString::number(cell_value));
    // ui->matrix->setItem(i, j, table_item);

    auto thread = new CellThread(i, j, this);
    connect(thread, &QThread::finished, thread, &QObject::deleteLater);
    connect(thread, &CellThread::temperature_calculated, this, &MainWindow::on_temperature_calculated);
    thread->start();
}
