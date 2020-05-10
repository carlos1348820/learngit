#include "smallwidget.h"
#include "ui_smallwidget.h"

smallWidget::smallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::smallWidget)
{
    ui->setupUi(this);
    void(QSpinBox::* spsignal)(int)=&QSpinBox::valueChanged;
    void(QSlider::* qslider)(int)=&QSlider::setValue;
    connect(ui->spinBox,spsignal,ui->horizontalSlider,qslider);//左动右也动
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);//右动左也动
}

smallWidget::~smallWidget()
{
    delete ui;
}

void smallWidget::setNum(int num)
{
    ui->spinBox->setValue(num);
}

int smallWidget::getNum()
{
    return ui->spinBox->value();
}
