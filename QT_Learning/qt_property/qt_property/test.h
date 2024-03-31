#ifndef TEST_H
#define TEST_H

#include <QObject>


class Test : public QObject
{
    Q_OBJECT
    QString m_message;
public:
    explicit Test(QObject *parent = nullptr);

    // property binding in QML
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged FINAL)

    QString message() const;
    void setMessage(const QString &newMessage);

signals:
    void messageChanged(QString message);
};

#endif // TEST_H
