#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QFile>
#include <QJsonDocument>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->push_button_load_data, &QPushButton::clicked, this, &MainWindow::on_load_data);
    connect(ui->push_button_start_game, &QPushButton::clicked, this, &MainWindow::on_start_search);
    connect(ui->spin_box_game_speed, &QDoubleSpinBox::valueChanged, this, &MainWindow::on_game_speed_changed)    ;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_data()
{
    const auto path = QFileDialog::getOpenFileName(this, "Select a JSON file", "", "JSON Files (*.json)");
    if (path.isEmpty()) {
        std::cerr << "Failed to find path to specified file\n";
        return;
    }

    QFile file{path};
    if (!file.open(QFile::ReadOnly)) {
        std::cerr << "Failed to open specified file\n";
        return;
    }

    const auto map = QJsonDocument::fromJson(file.readAll()).toVariant().toMap();

    m_map.fromQVariant(map.value("mapa"));

    qDeleteAll(m_hunters);
    m_hunters.clear();

    for (const auto &hunter_entry : map.value("tragaci").toList()) {
        TreasureHunter* hunter = new TreasureHunter();
        hunter->fromQVariant(hunter_entry);
        m_hunters.push_back(hunter);
    }

    m_can_start_search = true;
    m_map.set_game_speed(m_game_speed);
    display_hunters();
    display_map();
}

void MainWindow::on_start_search() {
    if (!m_can_start_search) {
        std::cerr << "Please enter the data first\n";
        return;
    }

    disable_controls();
    start_threads();
}

void MainWindow::on_game_speed_changed() {
    m_game_speed = ui->spin_box_game_speed->value();
    m_map.set_game_speed(m_game_speed);
}

void MainWindow::on_hunter_moved() {
    display_map();
}

void MainWindow::display_hunters() {
    ui->list_widget_finders->clear();
    for (const auto hunter : m_hunters) {
        ui->list_widget_finders->addItem(hunter->toQString());
    }
}

void MainWindow::display_map() {
    ui->table_wdiget_map->clear();
    const auto display_map = m_map.get_display_map();
    const auto [rows, cols] = m_map.get_map_size();
    ui->table_wdiget_map->setRowCount(rows);
    ui->table_wdiget_map->setColumnCount(cols);
    for (size_t i{}; i < rows; ++i) {
        for (size_t j{}; j < cols; ++j) {
            auto *table_item = new QTableWidgetItem;
            table_item->setText(display_map[i][j]);
            ui->table_wdiget_map->setItem(i, j, table_item);
        }
    }

    for (const auto &hunter : m_hunters) {
        const auto [x, y] = hunter->position();
        ui->table_wdiget_map->item(x, y)->setText(hunter->get_first_letter_name());
    }
}

void MainWindow::disable_controls() {
    ui->push_button_load_data->setDisabled(true);
    ui->push_button_start_game->setDisabled(true);
    ui->spin_box_game_speed->setDisabled(true);
}

void MainWindow::start_threads() {
    for (const auto &hunter : m_hunters) {
        HunterThread *thread = new HunterThread(hunter, m_map, &m_hunters_mutex, &m_map_mutex, m_game_speed);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);
        connect(thread, &HunterThread::hunter_moved, this, &MainWindow::on_hunter_moved);
        connect(thread, &HunterThread::thread_finished, this, &MainWindow::on_game_finished);
        thread->start();
    }
}

