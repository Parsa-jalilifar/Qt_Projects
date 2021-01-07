#include "searchdialog.h"
#include "ui_searchDialog.h"
#include <QDebug>
#include <qfile.h>
#include <QJsonParseError>
#include <QJsonObject>


searchDialog::searchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchDialog)
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

}

searchDialog::~searchDialog()
{
    delete ui;
}

void searchDialog::on_search_btn_clicked(){

//    QStringList key = ui->lineEdit_search->text();

    for (int i = 0 ;i < newsArray.size() ;i++ ) {
        QString title = newsArray[i].toObject().value("title").toString();
        QVector<QStringList> *keyList = new QVector<QStringList> () ;
        keyList->push_back(title.split(" "));

//        if(key == keyList->at(i))

    }




    // qDebug() << key;
    this->close();
}
