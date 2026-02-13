#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Fraction.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->push_button_increment1, &QPushButton::clicked,
            this, &MainWindow::on_increment_first);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_increment_first()
{
    const auto frac_text = ui->line_edit_fraction1->text();
    const auto fraction_elements = frac_text.split("/");
    if (fraction_elements.length() != 2) {
        ui->line_edit_result->setText("Prvi razlomak nije ispravnog formata");
        return;
    }
    bool is_numerator_parsed;
    const auto numerator = fraction_elements[0].toInt(&is_numerator_parsed);
    if (!is_numerator_parsed) {
        ui->line_edit_result->setText("Prvi razlomak nije ispravnog formata");
        return;
    }
    bool is_denominator_parsed;
    const auto denominator = fraction_elements[1].toUInt(&is_denominator_parsed);
    if (!is_denominator_parsed) {
        ui->line_edit_result->setText("Prvi razlomak nije ispravnog formata");
        return;
    }
    if (denominator == 0) {
        ui->line_edit_result->setText("Prvi razlomak nije ispravnog formata");
        return;
    }

    Fraction f(numerator, denominator);
    ++f;
    ui->line_edit_fraction1->setText(f);
    ui->line_edit_result->setText("");
}

void MainWindow::on_increment_second()
{

}
