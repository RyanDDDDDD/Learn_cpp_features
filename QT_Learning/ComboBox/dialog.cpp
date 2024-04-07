#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // initialize data
    init();

    // load data
    load();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::init()
{
    // clear all items
    ui->comboBox->clear();

    // add new items
    for (int i = 0; i < 10; ++i) {
        ui->comboBox->addItem("Item number: " + QString::number(i));
    }
}

void Dialog::load()
{
    QSettings settings("MySoft", "MyApp");

    QVariant value = settings.value("settings", 0);

    bool ok;
    int index = value.toInt(&ok);

    if (!ok) {
        QMessageBox::critical(this, "Loading Error", "Error during loading selcetion!");
        return;
    }

    if (index < ui->comboBox->count()) {
        ui->comboBox->setCurrentIndex(index);
    } else {
        ui->comboBox->setCurrentIndex(0);
    }
}

void Dialog::on_comboBox_currentIndexChanged(int index)
{
    ui->lbSelected->setText(QString::number(index) + " = " + ui->comboBox->currentText());
}


void Dialog::on_pushButton_clicked()
{
    QSettings settings("MySoft", "MyApp");

    settings.setValue("settings", ui->comboBox->currentIndex());

    QMessageBox::information(this, "Saved", "Selection saved, please close and re-open tha application");

    QVariant value = settings.value("settings", 0);
    bool ok;
    int index = value.toInt(&ok);

    if (ok) {
        qInfo() << ui->comboBox->currentIndex();
        qInfo() << "===================";
        qInfo() << index;
    }
}

