#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public slots:
    void onTimeOut();

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QTimer* _t = nullptr;
    int      _flag = 0;
    int x = 0;
    int y = 0;
    int width = 100;
    int height = 100;
    QColor  _color = Qt::blue;

};
#endif // WIDGET_H
