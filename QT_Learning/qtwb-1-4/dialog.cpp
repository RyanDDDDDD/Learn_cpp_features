#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // preferred way of signal-slot connection
    connect(ui->btnConnect, &QPushButton::clicked, this, &Dialog::doStuff);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::doStuff()
{
    qInfo() << "Clicked " << QDateTime::currentDateTime().toString();
    // accept();
}

void Dialog::on_btnEditor_clicked()
{
    doStuff();
}

