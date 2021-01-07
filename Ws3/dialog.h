#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:

     Dialog(QString name,QString city,QString street,QString aptNum,QString postalCode,
            QString pizzaSize,QStringList selectedcheckBox,QWidget *parent= nullptr);
    ~Dialog();

     void exitApp();
private:
    Ui::Dialog *ui;


};

#endif // DIALOG_H
