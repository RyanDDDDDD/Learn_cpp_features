#include "widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    _t = new QTimer(this);
    connect(_t, &QTimer::timeout, this, &Widget::onTimeOut);
    _t->setInterval(2000);
    _t->setSingleShot(true);
    _t->start();
}

Widget::~Widget() {}

void Widget::onTimeOut()
{
    qInfo() << "change color";
    _color = Qt::red;
    width = 50;
    height = 50;
    update(x, y, width, height);
}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.fillRect(x, y, width, height, _color);
}
