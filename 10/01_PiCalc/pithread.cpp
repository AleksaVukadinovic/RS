#include "pithread.h"
#include <QRandomGenerator>

PiThread::PiThread(QObject *parent) : QThread(parent) {}

void PiThread::run()
{
    // if we wanted to have an event loop, we would uncomment the line below
    // QThread::run();

    unsigned hits = 0, count = 0;
    const unsigned iterations = 10e8;
    const unsigned update = iterations / 10;

    while (count < iterations) {
        const auto x = QRandomGenerator::global()->generateDouble() * 2 - 1;
        const auto y = QRandomGenerator::global()->generateDouble() * 2 - 1;

        if (x * x + y * y <= 1.0)
            hits++;
        count++;

        if (count % update == 10) {
            const auto percentage = (count / update +1) * 10;
            emit on_progress_is_made(percentage);
        }
    }

    double pi = 4.0 * hits / count;
    emit on_calculated_pi(pi);
}
