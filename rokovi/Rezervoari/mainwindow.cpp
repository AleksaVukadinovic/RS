#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include <QVariantMap>
#include <QXmlStreamReader>
#include <iostream>
#include"sourcethread.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->push_button_load_sources, &QPushButton::clicked, this, &MainWindow::on_laod_sources);
    connect(ui->push_button_start_transfer, &QPushButton::clicked, this, &MainWindow::on_start_transfer);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_laod_sources() {
    const auto path = QFileDialog::getOpenFileName(this, "Chose XML file containg sources", "", "XML Files (*.xml)");
    if (path.isEmpty()) {
        std::cerr << "Failed to find the path to the provided file" << std::endl;
        return;
    }

    QFile file{path};
    if (!file.open(QFile::ReadOnly)) {
        std::cerr << "Failed to open the provided file" << std::endl;
        return;
    }

    qDeleteAll(m_sources);
    m_sources.clear();
    ui->list_widget_sources->clear();

    auto reader = QXmlStreamReader(&file);
    reader.readNextStartElement();
    unsigned total_volume = 0;
    while (reader.readNextStartElement()) {
        QVariantMap map;

        reader.readNextStartElement();
        auto volume = reader.readElementText().toUInt();
        map.insert("volume", volume);
        total_volume += volume;

        reader.readNextStartElement();
        auto name = reader.readElementText();
        map.insert("name", name);

        Source *source = new Source();
        source->fromQVariant(map);
        ui->list_widget_sources->addItem(source->toQString());
        m_sources.push_back(source);
        reader.readNextStartElement();
    }

    ui->line_edit_total_sources->setText(QString::number(total_volume));
    file.close();
}

void MainWindow::on_start_transfer() {
    const int total_tank = ui->line_edit_total_tank->text().toUInt();
    if (total_tank < 0) {
        ui->line_edit_total_tank->setText("Ukupna zapremina mora biti pozitivan broj");
        return;
    }

    ui->line_edit_current_tank->setText("0");
    ui->line_edit_current_loss->setText("0");

    start_threads();
}



void MainWindow::start_threads()
{
    for (const auto souce : m_sources) {
        auto thread = new SourceThread(m_sources, &m_mutex);

        connect(thread, &SourceThread::thread_finished, this, &MainWindow::on_thread_finished);
        connect(thread, &QThread::finished, thread, &QThread::deleteLater);

        thread->start();
    }
}

void MainWindow::on_thread_finished(unsigned source_idx, unsigned volume) {
    QMutexLocker lock(&m_mutex);
    ui->list_widget_sources->item(source_idx)->setText(m_sources[source_idx]->toQString());

    auto total = ui->line_edit_total_tank->text().toUInt();
    auto current = ui->line_edit_current_tank->text().toUInt();

    if(current + volume <= total){
        ui->line_edit_current_tank->setText(QString::number(current + volume));
    } else {
        auto loss = ui->line_edit_current_loss->text().toUInt();
        ui->line_edit_current_tank->setText(QString::number(total));
        loss += current + volume - total;
        ui->line_edit_current_loss->setText(QString::number(loss));
    }

}
