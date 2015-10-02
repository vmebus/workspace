#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

      connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(chooseSource()));
      connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Sobel()));
      connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(LoG()));
      connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->label,SLOT(setNum(int)));
}


void Widget::Sobel()
{
    int i,j;
    int Gx,Gy,Mag;

    int TH = ui->horizontalSlider->value();
    for(j=1; j<rsltImg.height()-1; j++)
    {
        for(i=1; i<rsltImg.width()-1; i++)
        {
            // horizontal
            Gx = qGray(srcImg.pixel(i-1, j+1)) + 2*qGray(srcImg.pixel(i, j+1)) + qGray(srcImg.pixel(i+1, j+1))
                      -qGray(srcImg.pixel(i-1, j-1)) - 2*qGray(srcImg.pixel(i, j-1)) - qGray(srcImg.pixel(i+1, j-1));
            // vertical
            Gy = qGray(srcImg.pixel(i+1, j-1)) + 2*qGray(srcImg.pixel(i+1, j)) + qGray(srcImg.pixel(i+1, j+1))
                     -qGray(srcImg.pixel(i-1, j-1)) - 2*qGray(srcImg.pixel(i-1, j)) - qGray(srcImg.pixel(i-1, j+1));
            Mag = abs(Gx) + abs(Gy);
            if(Mag > TH)
                rsltImg.setPixel(i, j, qRgb(255, 255, 255));
            else
                rsltImg.setPixel(i, j, qRgb(0, 0, 0));
        }
    }
    ui->toolButton_2->setIconSize(QSize(rsltImg.width(), rsltImg.height()));
    ui->toolButton_2->setIcon(QPixmap::fromImage(rsltImg));
}

void Widget::LoG()
{
    int i, j;
    int tmpPix;
    int TH = ui->horizontalSlider->value();
    for(j=2; j<rsltImg.height()-2; j++)
    {
        for(i=2; i<rsltImg.width()-2; i++)
        {
            // 5x5 LoG
            tmpPix = 16*qGray(srcImg.pixel(i, j))
                             - 2*( qGray(srcImg.pixel(i-1, j)) + qGray(srcImg.pixel(i+1, j))
                                      + qGray(srcImg.pixel(i, j-1)) + qGray(srcImg.pixel(i, j+1)) )
                             - qGray(srcImg.pixel(i, j-2)) - qGray(srcImg.pixel(i-1, j-1)) - qGray(srcImg.pixel(i+1, j-1))
                             - qGray(srcImg.pixel(i-2, j)) - qGray(srcImg.pixel(i+2, j)) - qGray(srcImg.pixel(i-1, j+1))
                             - qGray(srcImg.pixel(i+1, j+1)) - qGray(srcImg.pixel(i, j+2));


            if(tmpPix > TH)
                rsltImg.setPixel(i, j, qRgb(255, 255, 255));
            else
                rsltImg.setPixel(i, j, qRgb(0, 0, 0));
        }
    }
    ui->toolButton_2->setIconSize(QSize(rsltImg.width(), rsltImg.height()));
    ui->toolButton_2->setIcon(QPixmap::fromImage(rsltImg));
}

Widget::~Widget()
{
    delete ui;
}
void Widget::chooseSource(void)
{
    QString fileName =
            QFileDialog::getOpenFileName(this,
                          tr("Choose Source Image"));
    if (!fileName.isEmpty())
    {
        srcImg.load(fileName);
        srcImg = srcImg.convertToFormat(QImage::Format_RGB32);
        ui->toolButton->setIconSize(QSize(srcImg.width(),
                                          srcImg.height()));
        ui->toolButton->setIcon(QPixmap::fromImage(srcImg));

        rsltImg = QImage(srcImg.width(), srcImg.height(), QImage::Format_RGB32);

        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(true);
    }
}
