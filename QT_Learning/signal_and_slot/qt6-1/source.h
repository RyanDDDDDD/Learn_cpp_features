#ifndef SOURCE_H
#define SOURCE_H

#include <QObject>

class Source : public QObject
{
    Q_OBJECT
public:
    explicit Source(QObject *parent = nullptr);

    void test();


// dont need to define signals, what we need to do with singals is using connect() to
// to pass signal from an object to the slot of another object via emit
signals:
    void mySignal(QString message);

public slots:


};


#endif // SOURCE_H
