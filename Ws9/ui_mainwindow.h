/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionHelp;
    QAction *actionExit;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *left_verticalLayout;
    QHBoxLayout *left_horizontalLayout;
    QLineEdit *lineEdit;
    QScrollArea *scrollArea_news_left;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QVBoxLayout *news_chooser_layout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *right_verticalLayout;
    QLabel *label;
    QFrame *line;
    QLabel *news_imageView;
    QFrame *line_2;
    QLabel *news_paragraph;
    QLabel *news_paragraph2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1127, 602);
        actionHelp = new QAction(MainWindow);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon;
        icon.addFile(QString::fromUtf8("icons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QString::fromUtf8(":/icons/help.png"), QSize(), QIcon::Normal, QIcon::On);
        actionHelp->setIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icons/exit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_2 = new QVBoxLayout(centralwidget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, 0, 10, 10);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setStyleSheet(QString::fromUtf8("color:rgb(0, 39, 118);\n"
"font: 63 20pt \"Yu Gothic UI Semibold\";"));
        label_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);

        verticalLayout_2->addWidget(label_2);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        left_verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        left_verticalLayout->setObjectName(QString::fromUtf8("left_verticalLayout"));
        left_verticalLayout->setSizeConstraint(QLayout::SetNoConstraint);
        left_verticalLayout->setContentsMargins(0, 0, 0, 0);
        left_horizontalLayout = new QHBoxLayout();
        left_horizontalLayout->setObjectName(QString::fromUtf8("left_horizontalLayout"));
        lineEdit = new QLineEdit(verticalLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        left_horizontalLayout->addWidget(lineEdit);


        left_verticalLayout->addLayout(left_horizontalLayout);

        scrollArea_news_left = new QScrollArea(verticalLayoutWidget);
        scrollArea_news_left->setObjectName(QString::fromUtf8("scrollArea_news_left"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollArea_news_left->sizePolicy().hasHeightForWidth());
        scrollArea_news_left->setSizePolicy(sizePolicy1);
        scrollArea_news_left->setMinimumSize(QSize(0, 0));
        scrollArea_news_left->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 357, 454));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        news_chooser_layout = new QVBoxLayout();
        news_chooser_layout->setSpacing(5);
        news_chooser_layout->setObjectName(QString::fromUtf8("news_chooser_layout"));
        news_chooser_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        news_chooser_layout->setContentsMargins(0, 0, 0, 0);

        gridLayout->addLayout(news_chooser_layout, 0, 0, 1, 1);

        scrollArea_news_left->setWidget(scrollAreaWidgetContents);

        left_verticalLayout->addWidget(scrollArea_news_left);

        splitter->addWidget(verticalLayoutWidget);
        scrollArea = new QScrollArea(splitter);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setMinimumSize(QSize(740, 400));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 738, 487));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        right_verticalLayout = new QVBoxLayout();
        right_verticalLayout->setObjectName(QString::fromUtf8("right_verticalLayout"));
        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setStyleSheet(QString::fromUtf8("font: 75 16pt \"Tahoma\";"));
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label->setWordWrap(true);

        right_verticalLayout->addWidget(label);

        line = new QFrame(scrollAreaWidgetContents_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        right_verticalLayout->addWidget(line);

        news_imageView = new QLabel(scrollAreaWidgetContents_2);
        news_imageView->setObjectName(QString::fromUtf8("news_imageView"));
        news_imageView->setMargin(15);

        right_verticalLayout->addWidget(news_imageView);

        line_2 = new QFrame(scrollAreaWidgetContents_2);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        right_verticalLayout->addWidget(line_2);

        news_paragraph = new QLabel(scrollAreaWidgetContents_2);
        news_paragraph->setObjectName(QString::fromUtf8("news_paragraph"));
        news_paragraph->setStyleSheet(QString::fromUtf8("font: 10pt \"Tahoma\";"));
        news_paragraph->setWordWrap(true);
        news_paragraph->setMargin(5);

        right_verticalLayout->addWidget(news_paragraph);

        news_paragraph2 = new QLabel(scrollAreaWidgetContents_2);
        news_paragraph2->setObjectName(QString::fromUtf8("news_paragraph2"));
        news_paragraph2->setStyleSheet(QString::fromUtf8("font: 10pt \"Tahoma\";"));
        news_paragraph2->setWordWrap(true);
        news_paragraph2->setMargin(5);

        right_verticalLayout->addWidget(news_paragraph2);


        gridLayout_2->addLayout(right_verticalLayout, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents_2);
        splitter->addWidget(scrollArea);

        verticalLayout_2->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1127, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionHelp);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionHelp->setText(QCoreApplication::translate("MainWindow", "Help", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "News Article Viewer", nullptr));
        lineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search...", nullptr));
        label->setText(QString());
        news_imageView->setText(QString());
        news_paragraph->setText(QString());
        news_paragraph2->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
