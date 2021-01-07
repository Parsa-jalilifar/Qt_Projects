#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QJsonDocument>
#include <iostream>
#include <QJsonObject>
#include <QJsonArray>
#include <QSpinBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QFile inFile("../Ws8/newsFile.json"); //reading the json file
    inFile.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray data = inFile.readAll(); //putting all info in data variable
    inFile.close();

    //parse the jsone
    QJsonParseError errorPtr;
    QJsonDocument doc = QJsonDocument::fromJson(data, &errorPtr);
    if (doc.isNull())
        qDebug() << "Parse failed";

    QJsonObject rootObj = doc.object();
    newsArray = rootObj.value("articles").toArray();

    box = new QSpinBox();
    box->setMaximum(newsArray.size());
    box->setMinimum(1);
    ui->toolBar->addWidget(box);

    QAction *tLabel2= new QAction ();
    tLabel2->setText("to");
    ui->toolBar->addAction(tLabel2);


    box2 = new QSpinBox();
    box2->setMaximum(box->value());
    box2->setMinimum(1);
    ui->toolBar->addWidget(box2);

    QAction *tLabel1= new QAction ();
    tLabel1->setText("Articles:");
    ui->toolBar->addAction(tLabel1);


    connect(box, QOverload<int>::of(&QSpinBox::valueChanged), this,&MainWindow::showNews);
    connect(box2, QOverload<int>::of(&QSpinBox::valueChanged), this,&MainWindow::showNews);

    QLabel *label = new QLabel();
    label->setText(newsArray[0].toObject().value("title").toString());
    QFont font;
    font.setBold(true);
    font.setFamily("Segoe UI");
    font.setPointSize(14);
    label->setFont(font);
    label->setWordWrap(true);
    ui->vLayout->addWidget(label);

    QPixmap image(newsArray[0].toObject().value("image").toString());
    QLabel *imgView = new QLabel();
    imgView->setPixmap(image);
    imgView->setScaledContents( true );
    imgView->setFixedWidth(400);
    imgView->setFixedHeight(300);
    ui->vLayout->addWidget(imgView);

    QLabel *newsText = new QLabel();
    newsText->setText(newsArray[0].toObject().value("text").toString());
    QFont paragraphFont;
    paragraphFont.setFamily("Segoe UI");
    paragraphFont.setPointSize(10);
    newsText->setFont(paragraphFont);
    newsText->setMaximumWidth(750);
    newsText->setWordWrap(true);
    ui->vLayout->addWidget(newsText);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::closeAllWindows();
}

void MainWindow::showNews(){

    box2->setMaximum(box->value());

    deleteNews();

    int start = box2->value()-1;
    for (int i = start; i < box->value() ;i++ ) {
        QLabel *label = new QLabel();
        label->setText(newsArray[i].toObject().value("title").toString());
        QFont font;
        font.setBold(true);
        font.setFamily("Segoe UI");
        font.setPointSize(14);
        label->setFont(font);
        label->setWordWrap(true);
        ui->vLayout->addWidget(label);

        QPixmap image(newsArray[i].toObject().value("image").toString());
        QLabel *imgView = new QLabel();
        imgView->setPixmap(image);
        imgView->setScaledContents( true );
        imgView->setFixedWidth(400);
        imgView->setFixedHeight(300);
        ui->vLayout->addWidget(imgView);

        QLabel *newsText = new QLabel();
        newsText->setText(newsArray[i].toObject().value("text").toString());
        QFont paragraphFont;
        paragraphFont.setFamily("Segoe UI");
        paragraphFont.setPointSize(10);
        newsText->setFont(paragraphFont);
        newsText->setMaximumWidth(750);
        newsText->setWordWrap(true);
        ui->vLayout->addWidget(newsText);

    }
}

void MainWindow::deleteNews(){
    if ( ui->vLayout != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->vLayout->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }

    }
}
