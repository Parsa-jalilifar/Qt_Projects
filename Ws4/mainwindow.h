#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QVector>
#include <QCheckBox>
#include <QToolButton>

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

    void on_add_btn_clicked();

    void on_remove_btn_clicked();

    void on_actionSave_triggered();

    void on_actionLoad_triggered();

private:

    QToolButton* add_Tool(int index);
    bool check_tools(int index);

    QVector <int> *toolbar3_tools;
    QVector <int> *toolbar2_tools;
    QVector <int> *toolbar1_tools;
    QVector <int> *toolbar_saved;

    QVector <QPixmap> *iconImageList;
    QVector <QCheckBox*> *toolList;

    QStringList toolOptions = { "3d",
                                "Color Picker",
                                "Color","Copy",
                                "Crop", "Cut",
                                "Eraser", "Fill",
                                "Fonts", "Frame",
                                "Magnifier","Marker", "Minus",
                                "Notebook", "Paint-brush",
                                "Paste", "Pen",
                                "Pencil", "Plus",
                                "Redo",
                                "Resize", "Rotate",
                                "Select", "Shape",
                                "Share", "Size",
                                "Text-Box", "Undo",
                                "User-Finder", "Voice"
                              };
    int toolbar1_count;
    int toolbar2_count;
    int toolbar3_count;

    QAction *tag1;
    QAction *tag2;
    QAction *tag3;

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
