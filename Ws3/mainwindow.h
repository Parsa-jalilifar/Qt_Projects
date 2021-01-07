#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCheckBox>
#include <QMainWindow>
#include <qlineedit.h>
#include <qvector.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void onReset();
    void toppingChecker();

    void order();
private slots:
    void on_size_selector_currentTextChanged(const QString &arg1);

private:
    QStringList toppingOptions = {"ham", "pepperoni", "green pepper", "mushroom",
                                  "pineapple", "onion", "artichokes", "black olives","extra cheese"};
    QVector<QCheckBox*> *clist;
    QString name;
    QString city;
    QString street;
    QString  aptNum;
    QString postalCode;
    QString pizzaSize;
    QStringList selectedcheckBox;
    int checkCounter;
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
