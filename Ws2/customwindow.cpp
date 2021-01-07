#include "customwindow.h"

#include <QHBoxLayout>
#include <QPushButton>

CustomWindow::CustomWindow(QWidget *parent)
    : QWidget(parent)
{
    // making slider with its label
    slider = new QSlider(Qt::Horizontal,this);
    slider->setTickPosition(QSlider::TicksBelow);
    slider->setMinimum(0);
    slider->setMaximum(10);
    sliderLabel = new QLabel("0",this);

    // adding slider and label to horizontal layout
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(slider);
    hLayout->addWidget(sliderLabel);

    // adding horizontal layout to a vertical layout
    QVBoxLayout *vlayout = new QVBoxLayout(this);
    vlayout->addLayout(hLayout);

    // making + and _ buttons and text label for slider number
    textLabel = new QLabel("Zero", this);
    QPushButton *plsBtn = new QPushButton("+",this);
    QPushButton *minBtn = new QPushButton("-",this);

    // adding two buttons and one label to a grid layout
    QGridLayout *grid = new QGridLayout(this);
    grid->addWidget(textLabel,0,0);
    grid->addWidget(plsBtn,0,1);
    grid->addWidget(minBtn,0,2);

    // adding grid layout to vertical layout
    vlayout->addLayout(grid);
//    setLayout(vlayout);

    // connecting the each featuer to a function
    connect(slider, &QSlider::valueChanged, sliderLabel,
            static_cast<void (QLabel::*)(int)>(&QLabel::setNum));
    connect(slider, &QSlider::valueChanged, this,&CustomWindow::numToString);
    connect(plsBtn, &QPushButton::clicked, this, &CustomWindow::OnPlus);
    connect(minBtn, &QPushButton::clicked, this, &CustomWindow::OnMinus);


}

CustomWindow::~CustomWindow(){}

// it returns a text number
void CustomWindow::numToString(int num){
    QStringList numWords = {"Zero","One","Two","three","Four","Five","Six","Seven","Eigth","Nine","Ten"};
    textLabel->setText(numWords.at(num));
}

// adding one to the slider number and changing the position of the slider
void CustomWindow::OnPlus() {
    int val = sliderLabel->text().toInt();
    if(val<10){
        val++;
        slider->setSliderPosition(val);
        sliderLabel->setText(QString::number(val));
    }
}

// removing one from the slider number and changing the position of the slider
void CustomWindow::OnMinus() {
    int val = sliderLabel->text().toInt();
    if(val > 0){
        val--;
        slider->setSliderPosition(val);
        sliderLabel->setText(QString::number(val));
    }
}


