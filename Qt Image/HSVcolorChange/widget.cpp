#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowTitle("HSV Color Changing!");
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
    changingColor();
}

void Widget::changingColor(void)
{
    int i,j;
    QColor color;

    desImg = QImage(srcImg.width(), srcImg.height(), QImage::Format_ARGB32);

    for (j=0; j<srcImg.height(); j++) {
        for (i=0; i<srcImg.width(); i++){

            color = srcImg.pixel(i,j);

            if (color.hue() <330 && color.hue()>270)
            {
                color.setHsv(color.hue()+120,color.saturation(),color.value());
            }
            desImg.setPixel(i,j,color.rgb());
        }
    }

    ui->toolButton_2->setIconSize(QSize(desImg.width(), desImg.height()));
    ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));


}
