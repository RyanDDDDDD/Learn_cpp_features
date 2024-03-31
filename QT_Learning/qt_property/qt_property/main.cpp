#include <QCoreApplication>

#include "test.h"
#include "watcher.h"

#include <QVariant>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Test tester;
    Watcher destination;

    QObject::connect(&tester, &Test::messageChanged, &destination, &Watcher::messageChanged);

    // looking for a property called message and call the setter
    tester.setProperty("message", QVariant("Hello World"));

    tester.setMessage("testing");

    return a.exec();
}
