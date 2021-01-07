#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog.h"
#include <QVector>
#include <qcheckbox.h>

#include <qvector.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Adding items to QComboBox
    ui->size_selector->addItems({"small","medium","large"});

    // To have access to our checkBoxs later i put them inside of a vector
    clist = new QVector<QCheckBox*>();

    // Adding checkboxes to one layout
    for (int i=0;i<toppingOptions.size() ;i++ ) {
        QCheckBox *boxItem = new QCheckBox();
        boxItem->setText(toppingOptions.at(i));
        clist->push_back(boxItem);
        connect(boxItem, &QCheckBox::clicked,this,&MainWindow::toppingChecker);
        ui->groupBoxLayout->addWidget(boxItem);
    }

    // Connect reset button to onReset function
    connect(ui->reset_btn, &QPushButton::clicked, this, &MainWindow::onReset);
    connect(ui->order_btn, &QPushButton::clicked, this, &MainWindow::order);

}


MainWindow::~MainWindow()
{
    delete ui;
}

// count number of selected topping and if it is three it close reset o checkboxes
void MainWindow::toppingChecker(){

    checkCounter = 0;

    for (int i = 0; i < clist->size(); i++) {
        if (clist->at(i)->isChecked()) {
            checkCounter++;
        }
    }

    if (checkCounter == 3) {
        for (int i = 0; i < ui->groupBoxLayout->count(); ++i) {
            QWidget *widget = ui->groupBoxLayout->itemAt(i)->widget();
            if (widget != NULL) {
                widget->setEnabled(false);
                ui->size_selector->setDisabled(true);
            }
        }
    }
}


// when user clicks on order button corder and user information will display for confirming the order
void MainWindow::order()
{
    // seting customer inputs
    name = ui->name_input->text();
    city = ui->city_input->text();
    street = ui->street_input->text();
    aptNum = ui->apt_input->text();
    postalCode = ui->postalCode_input->text();
    pizzaSize = ui->size_selector->currentText();

    // finding selected checkBoxes
    for (int i = 0; i < clist->size(); i++) {
        if (clist->at(i)->isChecked()) {
            selectedcheckBox.append(toppingOptions.at(i));
        }
    }

    // making user unable to order if he has not enterd the needed information
    if (name != "" && city != "" && street != "" && postalCode != "" && pizzaSize != "" ) {
        if (selectedcheckBox.size() == 3) {
            Dialog *orderResult = new Dialog(name,city,street,aptNum,postalCode,pizzaSize,selectedcheckBox,this);
            orderResult->setModal(true);
            orderResult->exec();
        }
    }
}


// Reseting all choices which had done in order section
void MainWindow::onReset() {

    ui->size_selector->setDisabled(false);
    for (int i = 0; i < clist->size(); i++) {
        if (clist->at(i)->isChecked()) {
            clist->at(i)->setCheckState(Qt::Unchecked);
        }
    }

    for (int i = 0; i < ui->groupBoxLayout->count(); ++i) {
        QWidget *widget = ui->groupBoxLayout->itemAt(i)->widget();
        if (widget != NULL) widget->setDisabled(false);
    }
}


// disabling the extra cheese checkBox for large pize
void MainWindow::on_size_selector_currentTextChanged(const QString &pizzaSize)
{
    if (pizzaSize == "large") {
        clist->at(clist->size()-1)->setDisabled(true);
    } else {
        clist->at(clist->size()-1)->setDisabled(false);
    }
}

