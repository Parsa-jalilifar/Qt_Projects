#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QApplication>
#include <QCheckBox>
#include <QIcon>
#include <QToolButton>
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    toolbar1_count = 0;
    toolbar2_count = 0;
    toolbar3_count = 0;

    toolList = new QVector<QCheckBox*>();
    iconImageList = new  QVector<QPixmap>();

    // Adding checkboxes to one layout
    for (int i=0;i<toolOptions.size() ;i++ ) {

        QCheckBox *boxItem = new QCheckBox();
        boxItem->setText(toolOptions.at(i));
        toolList->push_back(boxItem);

        if (i < 10) {
            ui->verticalLayout->addWidget(boxItem);

        }else if (i < 20){
            ui->verticalLayout_2->addWidget(boxItem);
        }else{
           ui->verticalLayout_3->addWidget(boxItem);
        }

        QPixmap Icon(":/toolbar icons/" + toolOptions.at(i) + ".png");
        iconImageList->append(Icon);

    }

    ui->toolbarSelector->addItems({"toolBar 1","toolBar 2","toolBar 3"});

    tag1 = new QAction(tr("&Toolbar 1 "));
    tag2 = new QAction(tr("&Toolbar 2 "));
    tag3 = new QAction(tr("&Toolbar 3 "));

    ui->toolBar->addAction(tag1);
    ui->toolBar_2->addAction(tag2);
    ui->toolBar_3->addAction(tag3);

    toolbar1_tools = new QVector <int>;
    toolbar2_tools = new QVector <int>;
    toolbar3_tools = new QVector <int>;
    toolbar_saved = new QVector <int>;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::closeAllWindows();
}

void MainWindow::on_add_btn_clicked()
{

    if (ui->toolbarSelector->currentText() == "toolBar 1") {

        for (auto i = 0; i < toolList->size(); i++) {

            if (toolbar1_count == 10) {
                break;
            } else if (toolList->at(i)->isChecked() && !toolbar1_tools->contains(i)) {
                ui->toolBar->addWidget(add_Tool(i));
                toolbar1_tools->append(i);
                toolbar1_count++;
            }
        }

    }else if (ui->toolbarSelector->currentText() == "toolBar 2") {

        for (auto i = 0; i < toolList->size(); i++) {

            if (toolbar2_count == 10) {
                break;
            } else if (toolList->at(i)->isChecked() && !toolbar2_tools->contains(i)) {
                ui->toolBar_2->addWidget(add_Tool(i));
                toolbar2_tools->append(i);
                toolbar2_count++;
            }
        }

    }else {

        for (auto i = 0; i < toolList->size(); i++) {

            if (toolbar3_count == 10) {
                break;
            } else if (toolList->at(i)->isChecked() && !toolbar3_tools->contains(i)) {
                ui->toolBar_3->addWidget(add_Tool(i));
                toolbar3_tools->append(i);
                toolbar3_count++;
            }
        }

    }

}

void MainWindow::on_remove_btn_clicked()
{

    if (ui->toolbarSelector->currentText() == "toolBar 1") {
        ui->toolBar->clear();
        ui->toolBar->addAction(tag1);
        toolbar1_tools->clear();
        toolbar1_count = 0;

    } else if(ui->toolbarSelector->currentText() == "toolBar 2" ){
        ui->toolBar_2->clear();
        ui->toolBar_2->addAction(tag2);
        toolbar2_tools->clear();
        toolbar2_count = 0;
    } else {
        ui->toolBar_3->clear();
        ui->toolBar_3->addAction(tag3);
        toolbar3_tools->clear();
        toolbar3_count = 0;
    }

}

QToolButton* MainWindow::add_Tool(int index){

    QToolButton *iconButton = new QToolButton();
    iconButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    QAction loadAction(QIcon(iconImageList->at(index)),toolOptions.at(index),iconButton);
    iconButton->addAction(&loadAction);
    iconButton->setDefaultAction(&loadAction);
    return iconButton;
}


void MainWindow::on_actionSave_triggered()
{
    statusBar()->showMessage("Saving...",1500);
    toolbar_saved->clear();

    if (ui->toolbarSelector->currentText() == "toolBar 1") {

        for (int i = 0; i < toolbar1_tools->size(); i++){
            toolbar_saved->append(toolbar1_tools->at(i));
        }

    }else if (ui->toolbarSelector->currentText() == "toolBar 2"){
        for (int i = 0; i < toolbar2_tools->size(); i++){
            toolbar_saved->append(toolbar2_tools->at(i));
        }

    }else {
        for (int i = 0; i < toolbar3_tools->size(); i++){
            toolbar_saved->append(toolbar3_tools->at(i));
        }
    }

}

void MainWindow::on_actionLoad_triggered()
{
    statusBar()->showMessage("Loading...",1500);

    if (ui->toolbarSelector->currentText() == "toolBar 1") {
        ui->toolBar->clear();
        ui->toolBar->addAction(tag1);
        toolbar1_tools->clear();
        toolbar1_count = toolbar_saved->size();

        for (auto i = 0; i < toolbar_saved->size(); i++) {
            ui->toolBar->addWidget(add_Tool(toolbar_saved->at(i)));
            toolbar1_tools->append(toolbar_saved->at(i));
        }

    }else if (ui->toolbarSelector->currentText() == "toolBar 2") {
        ui->toolBar_2->clear();
        ui->toolBar_2->addAction(tag2);
        toolbar2_tools->clear();
        toolbar2_count = toolbar_saved->size();

        for (auto i = 0; i < toolbar_saved->size(); i++) {
            ui->toolBar_2->addWidget(add_Tool(toolbar_saved->at(i)));
            toolbar2_tools->append(toolbar_saved->at(i));
        }

    }else {
        ui->toolBar_3->clear();
        ui->toolBar_3->addAction(tag3);
        toolbar3_tools->clear();
        toolbar3_count = toolbar_saved->size();

        for (auto i = 0; i < toolbar_saved->size(); i++) {
            ui->toolBar_3->addWidget(add_Tool(toolbar_saved->at(i)));
            toolbar3_tools->append(toolbar_saved->at(i));
        }

    }

}
