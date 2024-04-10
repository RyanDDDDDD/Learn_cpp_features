#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    load();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_buttonBox_accepted()
{
    save();
    accept();
}


void Dialog::on_buttonBox_rejected()
{
    reject();
}

void Dialog::load()
{
    ui->txtName->setText("");
    ui->sbAge->setValue(0);
    ui->sbQty->setValue(0);

    QFile file("file.dat");

    if(!file.exists()) {
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QDataStream s(&file);

    QString name;
    int age;
    double qty;
    s >> name;
    s >> age;
    s >> qty;

    ui->txtName->setText(name);
    ui->sbAge->setValue(age);
    ui->sbQty->setValue(qty);

    file.close();
}

void Dialog::save()
{
    QFile file("file.dat");

    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::critical(this, "Error", file.errorString());
        return;
    }

    QDataStream s(&file);
    s << ui->txtName->text();
    s << ui->sbAge->text();
    s << ui->sbQty->text();

    file.close();
    QMessageBox::information(this, "Saved", "We have saved the file!");

}

