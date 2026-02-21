#include "sourcethread.h"
#include <QRandomGenerator>
#include <QMutexLocker>

SourceThread::SourceThread(QVector<Source *> &sources, QMutex* mutex)
    : m_sources(sources)
    , m_mutex(mutex)
{

}

void SourceThread::run() {
    auto generator = QRandomGenerator::global();
    while (true) {
        QThread::msleep(generator->bounded(5, 11) * 100);

        const int n = m_sources.size();
        unsigned source_idx = generator->bounded(0, n);

        QMutexLocker lock(m_mutex);

        if (m_sources[source_idx]->volume() == 0) {
            continue;
        }

        unsigned fluid_to_remove = qMin(m_sources[source_idx]->volume(), generator->bounded(100u, 201u));
        m_sources[source_idx]->set_volume(m_sources[source_idx]->volume() - fluid_to_remove);

        emit thread_finished(source_idx, fluid_to_remove);
    }
}
