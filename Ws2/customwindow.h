#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H

#include <QLabel>
#include <QSlider>
#include <QWidget>


class CustomWindow : public QWidget
{
    Q_OBJECT

public:
    CustomWindow(QWidget *parent = nullptr);
    ~CustomWindow();
private slots:
    void OnPlus();
    void OnMinus();
    void numToString(int num);

private:
    QSlider *slider;
    QLabel  *sliderLabel;
    QLabel  *textLabel;
};
#endif // CUSTOMWINDOW_H
