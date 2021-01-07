#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QJsonArray>

namespace Ui {
class searchDialog;
}

class searchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit searchDialog(QWidget *parent = nullptr);
    ~searchDialog();

private slots:
    void on_search_btn_clicked();

private:
    QJsonArray newsArray;
    QVector<int> *foundedKey;
    Ui::searchDialog *ui;
};

#endif // SEARCHDIALOG_H
