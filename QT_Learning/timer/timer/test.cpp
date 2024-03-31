#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{
    // when the m_timer(our private member get timeout, emit signal to the slot of Test)
    connect(&m_timer,&QTimer::timeout, this, &Test::timeout);

    m_timer.setInterval(1000);
    m_timer.start();
    // m_timer.stop();
}

void Test::timeout()
{
    qInfo() << "Test!";
    ++count;
    if (count >= 3) {
        m_timer.stop();
    }
}
