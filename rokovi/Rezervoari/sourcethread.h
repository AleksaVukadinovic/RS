#ifndef SOURCETHREAD_H
#define SOURCETHREAD_H

#include <QObject>
#include <QThread>
#include <QVector>
#include <QMutex>
#include "source.h"

class SourceThread : public QThread
{
    Q_OBJECT
public:
    explicit SourceThread(QVector<Source *> &sources, QMutex* mutex);

    void run() override;

signals:
    void thread_finished(unsigned source_idx, unsigned volume);

private:
    QVector<Source *> m_sources;
    QMutex *m_mutex;
};

#endif // SOURCETHREAD_H
