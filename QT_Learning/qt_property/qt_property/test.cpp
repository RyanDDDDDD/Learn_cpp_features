#include "test.h"

Test::Test(QObject *parent)
    : QObject{parent}
{}

QString Test::message() const
{
    return m_message;
}

void Test::setMessage(const QString &newMessage)
{
    m_message = newMessage;
    emit messageChanged(m_message);
}
