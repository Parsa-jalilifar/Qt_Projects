#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "clickablelabel.h"
#include <QFile>
#include <QVector>
#include <QJsonParseError>
#include <QJsonObject>
#include <QGroupBox>
#include <QGroupBox>
#include <qgroupbox.h>
#include <QMessageBox>
#include <QToolButton>
#include <QRegularExpression>
#include <QSignalMapper>
#include <searchdialog.h>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFile inFile("./newsFile.json"); //reading the json file
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


    connect(ui->actionHelp, &QAction::triggered, this, &MainWindow::help);
    connect(ui->lineEdit, &QLineEdit::textChanged, this, &MainWindow::search);

    ui->news_chooser_layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->right_verticalLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    ui->line->setVisible(false);
    ui->line_2->setVisible(false);

    // showing news on the left panel in other for user to select
    showNewsSelector();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showNewsSelector(){
    for (int i = 0 ;i <newsArray.size() ;i++ )
        showItem(i);
}

void MainWindow::showItem(int i){

    QLabel *label = new ClickableLabel();
    label->setText(newsArray[i].toObject().value("title").toString());
    label->setWordWrap(true);
    QFont font;
    font.setBold(true);
    font.setFamily("Tahoma");
    label->setFont(font);

    QPixmap image(newsArray[i].toObject().value("image").toString());
    QLabel *imgView = new ClickableLabel();
    imgView->setPixmap(image);
    imgView->setScaledContents( true );
    imgView->setFixedWidth(280);
    imgView->setFixedHeight(180);

    QSignalMapper *signalMapper = new QSignalMapper (this) ;
    signalMapper -> setMapping (imgView, i);
    connect (imgView, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    connect (label, SIGNAL(clicked()), signalMapper, SLOT(map())) ;
    signalMapper -> setMapping (label, i);
    connect(signalMapper, SIGNAL(mapped(int)), this, SLOT(showDetail(int)));

    QGroupBox *card = new QGroupBox();
    card->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    card->setStyleSheet("background:#669999");

    QVBoxLayout *cardLayout = new QVBoxLayout();
    cardLayout->addWidget(label);
    cardLayout->addWidget(imgView);
    cardLayout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    card->setLayout(cardLayout);
    ui->news_chooser_layout->addWidget(card);
}

void MainWindow::showDetail(int i){

    ui->label->setText(newsArray[i].toObject().value("title").toString());

    ui->line->setVisible(true);

    QPixmap image(newsArray[i].toObject().value("image").toString());
    ui->news_imageView->setFixedWidth(680);
    ui->news_imageView->setFixedHeight(340);
    ui->news_imageView->setPixmap(image);
    ui->news_imageView->setScaledContents( true );

    ui->line_2->setVisible(true);

    ui->news_paragraph->setText(newsArray[i].toObject().value("text").toString());

    ui->news_paragraph2->setText(newsArray[i].toObject().value("text2").toString());
}

void MainWindow::help()
{
    QMessageBox *helpBox = new QMessageBox ();
    helpBox->setWindowTitle("Help");
    helpBox->setText("To view an article in detail, you can select it from left\n"
                     "column by clicking on the article. To search for an article,\n"
                     "start typing in the search bar located at the top of the left\n"
                     "column, and your search results will appear.\n");
    helpBox->exec();
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::closeAllWindows();
}

void MainWindow::search()
{
    QString key = ui->lineEdit->text();
    QString regkey = "(?i)(" + key + ")\w*";
    QRegularExpression re(regkey);
    QVector<int> *matches = new QVector<int>();

    if (key.size()  > 2){



        for (int i = 0 ;i <newsArray.size() ;i++ ) {
            QString title = newsArray[i].toObject().value("title").toString();
            QStringList keyList = title.split(" ");

            for (auto j = 0; j < keyList.size(); j++) {
                QRegularExpressionMatch match = re.match(keyList.at(j));
                if (match.hasMatch()){
                    matches->push_back(i);
                }
            }
        }
deleteNews();
        for (auto i = 0; i < matches->size(); i++)
            showItem(matches->at(i));

    }else if (key.isEmpty()){
        deleteNews();
        showNewsSelector();
    }
}

void MainWindow::deleteNews(){
    if ( ui->news_chooser_layout != NULL )
    {
        QLayoutItem* item;
        while ( ( item = ui->news_chooser_layout->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }

    }
}
