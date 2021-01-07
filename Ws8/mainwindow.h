#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonArray>
#include <qspinbox.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();
    void showNews();
    void deleteNews();

private:
    QJsonArray newsArray;
    QSpinBox *box;
    QSpinBox *box2;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
