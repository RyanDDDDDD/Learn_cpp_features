

#include <QCoreApplication>
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include "radio.h"
#include "station.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Radio boombox;
    Station* channels[3];

    // create some stations
    channels[0] = new Station(&boombox, 94, "Rock and Roll");
    channels[1] = new Station(&boombox, 87, "Hip Hop");
    channels[2] = new Station(&boombox, 104, "News");

    QObject::connect(&boombox, &Radio::quit, &a, &QCoreApplication::quit,Qt::QueuedConnection);

    do
    {
        qInfo() << "Enter on, off, test or quit";
        QTextStream qtIn(stdin);
        QString line = qtIn.readLine().trimmed().toUpper();

        if (line == "OFF") {
            qInfo() << "Turning the radio off";

            for (int i = 0; i < 3; ++i) {
                Station* channel = channels[i];

                QObject::disconnect(channel, &Station::send, &boombox, &Radio::listen);
            }

            qInfo() << "Radio is off";

        } else if (line == "ON") {
            qInfo() << "Turning the radio on";

            for (int i = 0; i < 3; ++i) {
                Station* channel = channels[i];

                QObject::connect(channel, &Station::send, &boombox, &Radio::listen);
            }

            qInfo() << "Radio is on";
        } else if (line == "TEST") {
            qInfo() << "Testing";

            for (int i = 0; i < 3; ++i) {
                Station* channel = channels[i];

                channel->broadcast("Brocasting live!");
            }

            qInfo() << "Test complete";
        } else if (line == "QUIT") {
            qInfo() << "quitting";

            emit boombox.quit();
            break;
        }

    } while (true);

    return a.exec();
}
