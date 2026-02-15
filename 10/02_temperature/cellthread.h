#ifndef CELLTHREAD_H
#define CELLTHREAD_H

#include <QThread>

class CellThread : public QThread
{
    Q_OBJECT
public:
    CellThread(int i, int j, QObject *parent = nullptr);
    void run() override;

private:
    int _i, _j;

signals:
    void temperature_calculated(int i, int j);
};

#endif // CELLTHREAD_H
