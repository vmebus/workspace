#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("Get Channels!");
    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(chooseSource()) );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::chooseSource(void)
{
    chooseImage(tr("Choose Source Image"), &srcImg, ui->toolButton);
}

void Widget::chooseImage(const QString &title, QImage *image, QToolButton *button)
{
    QString fileName = QFileDialog::getOpenFileName(this, title);

    if (!fileName.isEmpty())
    {
            loadImage(fileName, image, button);
    }
}

void Widget::loadImage(const QString &fileName, QImage *image, QToolButton *button)
{
    image->load(fileName);
    *image = image->convertToFormat(QImage::Format_RGB32);
    button->setIconSize(QSize(image->width(), image->height()));
    button->setIcon(QPixmap::fromImage(*image));
    getChannels();
}

void Widget::getChannels(void)
{
    int i,j;
    int tmpPixel;
    QRgb value;

    redImg = QImage(srcImg.width(), srcImg.height(), QImage::Format_ARGB32);
    greenImg = QImage(srcImg.width(), srcImg.height(), QImage::Format_ARGB32);
    blueImg = QImage(srcImg.width(), srcImg.height(), QImage::Format_ARGB32);

    for (j=0; j<srcImg.height(); j++) {
        for (i=0; i<srcImg.width(); i++){
            tmpPixel = qRed(srcImg.pixel(i,j));
            value = qRgb(tmpPixel,tmpPixel,tmpPixel);
            redImg.setPixel(i,j,value);

            tmpPixel = qGreen(srcImg.pixel(i,j));
            value = qRgb(tmpPixel,tmpPixel,tmpPixel);
            greenImg.setPixel(i,j,value);

            tmpPixel = qBlue(srcImg.pixel(i,j));
            value = qRgb(tmpPixel,tmpPixel,tmpPixel);
            blueImg.setPixel(i,j,value);
        }
    }

    ui->toolButton_2->setIconSize(QSize(redImg.width(), redImg.height()));
    ui->toolButton_2->setIcon(QPixmap::fromImage(redImg));

    ui->toolButton_3->setIconSize(QSize(greenImg.width(), greenImg.height()));
    ui->toolButton_3->setIcon(QPixmap::fromImage(greenImg));

    ui->toolButton_4->setIconSize(QSize(blueImg.width(), blueImg.height()));
    ui->toolButton_4->setIcon(QPixmap::fromImage(blueImg));
}
