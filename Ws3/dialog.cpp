#include "dialog.h"
#include "mainwindow.h"
#include "ui_dialog.h"


#include<QDebug>

Dialog::Dialog(QString name,QString city,QString street,QString aptNum,QString postalCode,
               QString pizzaSize,QStringList selectedcheckBox,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    // Setting informatin in side of dialog box
    ui->d_name->setText(name);
    ui->d_city->setText(city);
    ui->d_street->setText(street);
    ui->d_apt->setText(aptNum);
    ui->d_postalCode->setText(postalCode);
    ui->d_pizzaSize->setText(pizzaSize);

    if(selectedcheckBox.at(0) != ""){
        ui->d_topping1->setText("1) "+selectedcheckBox.at(0));
    }
    else{
        ui->d_topping1->setText("1) ");

    }

    if(selectedcheckBox.at(1) != ""){
        ui->d_topping2->setText("2) "+selectedcheckBox.at(1));
    } else {
        ui->d_topping2->setText("2) ");
    }

    if(selectedcheckBox.at(2) != nullptr){
        ui->d_topping3->setText("3) "+selectedcheckBox.at(2));
    } else {
        ui->d_topping3->setText("3) ");
    }

    // Connect submit button to close all windows
    connect(ui->Submit_btn, &QPushButton::clicked, this, &Dialog::exitApp);


}

Dialog::~Dialog()
{
    delete ui;
}

// It close all the windows + dialog box
void Dialog::exitApp() {
    QApplication::closeAllWindows();
    Dialog::close();
}
