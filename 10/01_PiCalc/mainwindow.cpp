#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pithread.h"
#include <QRandomGenerator>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->button_aproximate, &QPushButton::clicked, this, &MainWindow::on_calculate_pi);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calculate_pi() {
    ui->progress_bar->setValue(0);
    ui->line_edit_pi->setText("");

    PiThread *thread = new PiThread();

    connect(thread, &PiThread::on_calculated_pi, this, &MainWindow::on_calculated_pi);
    connect(thread, &PiThread::on_progress_is_made, this, &MainWindow::on_progress_is_made);
    connect(thread, &QThread::finished, thread, &QObject::deleteLater);

    thread->start();
}

void MainWindow::on_progress_is_made(int percentage)
{
    ui->progress_bar->setValue(percentage);
}

void MainWindow::on_calculated_pi(double pi)
{
    ui->line_edit_pi->setText(QString::number(pi));
}

