#ifndef PITHREAD_H
#define PITHREAD_H

#include <QThread>

class PiThread : public QThread
{
    Q_OBJECT
public:
    explicit PiThread(QObject *parent = nullptr);

protected:
    void run() override;

signals:
    void on_progress_is_made(int percentage);
    void on_calculated_pi(double pi);
};

#endif // PITHREAD_H
