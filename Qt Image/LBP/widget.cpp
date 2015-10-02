#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(chooseSource_1()));
    connect(ui->toolButton_2, SIGNAL(clicked()), this, SLOT(chooseSource_2()));
    connect(ui->toolButton_3, SIGNAL(clicked()), this, SLOT(chooseSource_3()));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->label, SLOT(setNum(int)));
}



void Widget::doLBP(QImage *image, QImage *desImg, QToolButton *desButton, QLabel *label)
{
    int i, j;
    MyByte Byte;
    *desImg = QImage( QSize(image->width()-2, image->height()-2), QImage::Format_RGB32 );

    const int threshold = ui->horizontalSlider->value();

    for(j=1; j<image->height()-1; j++){
       for(i=1; i<image->width()-1; i++){
           Byte.bit.bit0 = (qGray(image->pixel(i, j)) - qGray(image->pixel(i-1, j-1))) > threshold ? 1 : 0;
           Byte.bit.bit1 = (qGray(image->pixel(i, j)) - qGray(image->pixel(i, j-1))) > threshold ? 1 : 0;
           Byte.bit.bit2 = (qGray(image->pixel(i, j)) - qGray(image->pixel(i+1, j-1))) > threshold ? 1 : 0;
           Byte.bit.bit3 = (qGray(image->pixel(i, j)) - qGray(image->pixel(i-1, j))) > threshold ? 1 : 0;
           Byte.bit.bit4 = (qGray(image->pixel(i, j)) - qGray(image->pixel(i+1, j))) > threshold ? 1 : 0;
           Byte.bit.bit5 = (qGray(image->pixel(i, j)) - qGray(image->pixel(i-1, j+1))) > threshold ? 1 : 0;
           Byte.bit.bit6 = (qGray(image->pixel(i, j)) - qGray(image->pixel(i, j+1))) > threshold ? 1 : 0;
           Byte.bit.bit7 = (qGray(image->pixel(i, j)) - qGray(image->pixel(i+1, j+1))) > threshold ? 1 : 0;

           desImg->setPixel(i-1, j-1, qRgb(Byte.byte, Byte.byte, Byte.byte));
       }
    }
    desButton->setIconSize(QSize(desImg->width(), desImg->height()));
    desButton->setIcon(QPixmap::fromImage(*desImg));
    label->setNum(threshold);
}




void Widget::chooseSource_1(void)
{
    chooseImage(tr("Choose Source Image"),
                &srcImg_1, &LBPImg_1,
                ui->toolButton, ui->toolButton_4,
                ui->label_2);
}
void Widget::chooseSource_2(void)
{
    chooseImage(tr("Choose Source Image"),
                &srcImg_2, &LBPImg_2,
                ui->toolButton_2, ui->toolButton_5,
                ui->label_3);
}
void Widget::chooseSource_3(void)
{
    chooseImage(tr("Choose Source Image"),
                &srcImg_3, &LBPImg_3,
                ui->toolButton_3, ui->toolButton_6,
                ui->label_4);
}

void Widget::chooseImage(const QString &title, QImage *image, QImage *desImg,
                         QToolButton *button, QToolButton *desButton, QLabel *label)
{
    QString fileName = QFileDialog::getOpenFileName(this, title);
    if (!fileName.isEmpty())
    {
        loadImage(fileName, image, desImg, button, desButton, label);
    }
}

void Widget::loadImage(const QString &fileName, QImage *image, QImage *desImg,
                       QToolButton *button, QToolButton *desButton, QLabel *label)
{
    image->load(fileName);
    *image = image->convertToFormat(QImage::Format_RGB32);
    button->setIconSize(QSize(image->width(), image->height()));
    button->setIcon(QPixmap::fromImage(*image));

    doLBP(image, desImg, desButton, label);
}


Widget::~Widget()
{
    delete ui;
}
