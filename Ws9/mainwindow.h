#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QJsonArray>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void help();
    void on_search_btn_clicked();
    void search();
    void deleteNews();
    void showItem(int i);
public slots:
    void showNewsSelector();
    void showDetail(int i);

private slots:
    void on_actionExit_triggered();

private:
    QJsonArray newsArray;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
