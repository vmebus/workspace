#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(chooseSource()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(histEq()));

    hisImg = QImage(QSize(W,H),QImage::Format_RGB32);
    hisImg.fill(qRgb(255,255,255));
    hisEqImg = hisImg;
}

Widget::~Widget()
{
    delete ui;
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
        ui->toolButton_2->setIconSize(QSize(srcImg.width(),srcImg.height()));
        rsltImg = QImage(srcImg.width(), srcImg.height(), QImage::Format_RGB32);
        ui->pushButton->setEnabled(true);
        ui->toolButton_3->setIconSize(QSize(hisImg.width(),hisImg.height()));
        ui->toolButton_3->setIcon(QPixmap::fromImage(hisImg));
        ui->toolButton_4->setIconSize(QSize(hisEqImg.width(),hisEqImg.height()));
        ui->toolButton_4->setIcon(QPixmap::fromImage(hisEqImg));

        CalcHis(&srcImg, &hisImg, mtx, ui->toolButton_3);
    }
}

void Widget::CalcHis(QImage *Img, QImage *drawImg, unsigned int* hisMtx, QToolButton *button)
{
    int i, j;
    int tmpPix;
    unsigned int max = 0;
    int top;
    memset((void*)hisMtx,0,sizeof(int)*256);

    for(j=0; j<Img->height(); j++){
        for(i=0; i<Img->width(); i++){

            tmpPix = qGray(Img->pixel(i, j));
            hisMtx[tmpPix]++;
        }
    }

    for (max=0,i=0;i<hisSize;i++){
        if(hisMtx[i]>max)
            max = hisMtx[i];
    }

    painter.begin(drawImg);
    for (i=0;i<hisSize;i++){
        top=H-(hisMtx[i]*H)/max;
        painter.setPen(Qt::red);
        painter.drawLine(i,top,i,H);
    }
    painter.end();

    button->setIcon(QPixmap::fromImage(*drawImg));
}

void Widget::histEq(){
    CalcCDF(mtx,CDFMtx);
    ImgEqualization(&srcImg, &rsltImg,CDFMtx);
    CalcHis(&rsltImg, &hisEqImg, mtxEq, ui->toolButton_4);
}

void Widget::CalcCDF(unsigned int *hisMtx, unsigned int *CDFMtx)
{
    int i;
    bool firstVal = false;

    for (i=0; i<hisSize; i++){
        if (hisMtx[i]!=0){
            if(firstVal){
                CDFMtx[i]=hisMtx[i]+CDFMtx[i-1];
            }
            else {
                CDFMtx[i]=hisMtx[i];
            }
            firstVal=true;
        }
        else{
            CDFMtx[i] =0;
        }
    }
}

void Widget::ImgEqualization(QImage *srcImg, QImage *rsltImg, unsigned int *CDFMtx)
{
    int i,j;
    unsigned int CDFmin= (~0);
    int color;
    QColor tmpColor;

    for(i=0;i<hisSize;i++){
        if (CDFMtx[i]< CDFmin&&CDFMtx[i] !=0){
            CDFmin=CDFMtx[i];
        }
    }

    for(j=0;j<srcImg->height();j++){
        for(i=0;i<srcImg->width();i++){
            color = (CDFMtx[qGray(srcImg->pixel(i,j))]-CDFmin)*255/(srcImg->width()*srcImg->height()-CDFmin);
            tmpColor = srcImg->pixel(i,j);
            tmpColor.setHsv(tmpColor.hue(),tmpColor.saturation(),color);
            rsltImg->setPixel(i,j,qRgb(tmpColor.red(),tmpColor.green(),tmpColor.blue()));
        }
    }
    ui->toolButton_2->setIcon(QPixmap::fromImage(*rsltImg));
}
