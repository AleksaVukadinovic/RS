#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMutex>
#include "source.h"

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
    void on_laod_sources();
    void on_start_transfer();
    void on_thread_finished(unsigned source_idx, unsigned volume);

private:
    Ui::MainWindow *ui;
    QVector<Source *> m_sources;
    QMutex m_mutex;

    void start_threads();
};
#endif // MAINWINDOW_H
