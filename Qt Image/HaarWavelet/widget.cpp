#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(chooseSource()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Wavelet()));

}


void Widget::Wavelet(void)
{
    int cnt = ui->comboBox->currentIndex();
    int w = srcImg.width();
    int h = srcImg.height();

    rsltImg = srcImg;

    while(cnt-- && w!=1 && h!=1){
        dowavelet(w,h);
        w/=2;
        h/=2;
    }
    ui->toolButton_2->setIcon(QPixmap::fromImage(rsltImg));
}

void Widget::dowavelet(int w, int h)
{
    int i,j;
    int rowcnt,colcnt;
    int hlfW = w/2, hlfH = h/2;
    int color;
    int tmpPix1, tmpPix2;
    const int threshold = 10;
    QImage tmpImg = rsltImg;

    //horizontal
    for (j=0; j<h; j++){
        colcnt = 0;
        for (i=0; i<w; i+=2){
            tmpPix1 = qGray(tmpImg.pixel(i,j));
            tmpPix2 = qGray(tmpImg.pixel(i+1,j));
            color = (tmpPix1 + tmpPix2)/2;
            rsltImg.setPixel(colcnt,j,qRgb(color,color,color));
            color = abs(tmpPix1 - tmpPix2);
            color = (color > threshold) ? 255: 0;
            rsltImg.setPixel(colcnt+hlfW,j,qRgb(color,color,color));
            colcnt++;
        }
    }

    tmpImg = rsltImg; //copy image


    for (j=0; j<h; j+=2){
        rowcnt = 0;
        for (i=0; i<w; i++){
            tmpPix1 = qGray(tmpImg.pixel(i,j));
            tmpPix2 = qGray(tmpImg.pixel(i,j+1));
            color = (tmpPix1 + tmpPix2)/2;
            rsltImg.setPixel(i,rowcnt,qRgb(color,color,color));
            color = abs(tmpPix1 - tmpPix2);
            color = (color > threshold) ? 255: 0;
            rsltImg.setPixel(i,rowcnt+hlfH,qRgb(color,color,color));
        }
            rowcnt++;
    }
}


void Widget::chooseSource(void)
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Choose Source Image"));

    if (!fileName.isEmpty())
    {
        srcImg.load(fileName);
        srcImg = srcImg.convertToFormat(QImage::Format_RGB32);
        ui->toolButton->setIconSize(QSize(srcImg.width(),srcImg.height()));
        ui->toolButton->setIcon(QPixmap::fromImage(srcImg));

        rsltImg = srcImg;

        ui->toolButton_2->setIconSize(QSize(rsltImg.width(),rsltImg.height()));
        ui->pushButton->setEnabled(true);
    }
}


Widget::~Widget()
{
    delete ui;
}
