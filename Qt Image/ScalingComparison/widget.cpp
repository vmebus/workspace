#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(chooseSource()));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(setScale()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(doBilinear()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(doNearest()));
    scale = 1;

    setWindowTitle("Scaling Comparison!");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::setScale(void)
{
    scale =ui->horizontalSlider->value();
}

void Widget::doNearest(void)
{
    nrstImg = QImage(srcImg.width()*scale, srcImg.height()*scale, QImage::Format_RGB32);

    float i,j;
    int x,y;
    int tmpPix;

    for (j=0; j<nrstImg.height(); j++){
        for (i=0; i<nrstImg.width(); i++){
            x = i/scale+0.5;
            y = j/scale+0.5;

            if(x>=srcImg.width() && y>=srcImg.height()){
                x--;y--;
            }
            else if (x>=srcImg.width() && y<srcImg.height()){
                x--;
            }
            else if (x<srcImg.width() && y>=srcImg.height()){
                y--;
            }
            tmpPix =srcImg.pixel(x,y);
            nrstImg.setPixel(i,j,qRgb(qRed(tmpPix),qGreen(tmpPix),qBlue(tmpPix)));
        }
    }
    ui->toolButton_2->setIconSize(QSize(nrstImg.width(), nrstImg.height()));
    ui->toolButton_2->setIcon(QPixmap::fromImage(nrstImg));
}

void Widget::doBilinear(void)
{
    biImg = QImage(srcImg.width()*scale, srcImg.height()*scale, QImage::Format_RGB32);

    float i,j;
    int x,y;
    int rPix,gPix,bPix;
    float a,b,c,d;

    for (j=0; j<biImg.height(); j++){
        for (i=0; i<biImg.width(); i++){
            a = i/scale-(int)i/scale;
            b = j/scale-(int)j/scale;
            c=1-a;
            d=1-b;
            x=i/scale;
            y=j/scale;

            if((x+1)>=srcImg.width() && (y+1)>=srcImg.height()){
                x--;y--;
            }
            else if ((x+1)>=srcImg.width() && (y+1)<srcImg.height()){
                x--;
            }
            else if ((x+1)<srcImg.width() && (y+1)>=srcImg.height()){
                y--;
            }

            rPix = c*d*qRed(srcImg.pixel(x,y))+a*d*qRed(srcImg.pixel(x+1,y))+c*b*qRed(srcImg.pixel(x,y+1))+a*b*qRed(srcImg.pixel(x+1,y+1));
            gPix = c*d*qGreen(srcImg.pixel(x,y))+a*d*qGreen(srcImg.pixel(x+1,y))+c*b*qGreen(srcImg.pixel(x,y+1))+a*b*qGreen(srcImg.pixel(x+1,y+1));
            bPix = c*d*qBlue(srcImg.pixel(x,y))+a*d*qBlue(srcImg.pixel(x+1,y))+c*b*qBlue(srcImg.pixel(x,y+1))+a*b*qBlue(srcImg.pixel(x+1,y+1));

            biImg.setPixel(i,j,qRgb(rPix,gPix,bPix));
        }
    }
    ui->toolButton_3->setIconSize(QSize(biImg.width(), biImg.height()));
    ui->toolButton_3->setIcon(QPixmap::fromImage(biImg));
}

void Widget::chooseSource(void)
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose Source Image"));

    if (!fileName.isEmpty())
    {
            srcImg.load(fileName);
            srcImg = srcImg.convertToFormat(QImage::Format_RGB32);
            ui->toolButton->setIconSize(QSize(srcImg.width(), srcImg.height()));
            ui->toolButton->setIcon(QPixmap::fromImage(srcImg));
            ui->horizontalSlider->setEnabled(true);
            ui->pushButton->setEnabled(true);
    }

}
