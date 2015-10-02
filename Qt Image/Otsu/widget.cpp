#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(chooseSource()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(Otsu()));

    ui->pushButton->setEnabled(false);
    ui->lcdNumber->setSegmentStyle(QLCDNumber::Flat);
}

void Widget::Otsu()
{
    int OtsuTH;
    CalcHis(&srcImg,mtx);
    CalcCDF(mtx,CDFMtx);
    OtsuTH=getThreshold(&srcImg,mtx,CDFMtx);
    getBinaryImg(&srcImg,&rsltImg,OtsuTH);
    ui->pushButton->setEnabled(false);
    ui->toolButton->setIcon(QPixmap::fromImage(rsltImg));
    ui->lcdNumber->display(OtsuTH);
}


int Widget::getThreshold(QImage *img, unsigned int *hisMtx, unsigned int *CDFMtx)
{
    int i;
    unsigned int q1,q2,u1,u2;
    unsigned int csum,sum;
    int betweenVariance;
    int OtsuTh = 0;
    int max;
    int totalP;
    totalP = img->width()*img->height();

    for (sum=0,i=0;i<hisSize;i++){
        sum += i*hisMtx[i];
    }

    for(max=0,csum=0,i=0;i<hisSize;i++){
        if(CDFMtx[i]==0) {continue;}
        q1=CDFMtx[i];
        q2=totalP-q1;
        if (q2==0) {break;}
        csum +=i*hisMtx[i];
        u1=csum/q1;
        u2=(sum-csum)/q2;
        betweenVariance = q1*q2*(u1-u2)*(u1-u2);
        if(betweenVariance>max){
            max=betweenVariance;
            OtsuTh =  i;
        }
    }
    return OtsuTh;
}

void Widget::getBinaryImg(QImage *srcImg, QImage *rsltImg, int TH)
{
    int i, j;
    int tmpPix;

    for(j=0; j<srcImg->height(); j++){
        for(i=0; i<srcImg->width(); i++){

            tmpPix = (qGray(srcImg->pixel(i, j))>TH)?255:0;
            rsltImg->setPixel(i,j,qRgb(tmpPix,tmpPix,tmpPix));
        }
    }
}

void Widget::CalcHis(QImage *Img,unsigned int* hisMtx)
{
    int i, j;
    int tmpPix = 0;

    memset((void*)hisMtx,0,sizeof(int)*hisSize);

    for(j=0; j<Img->height(); j++){
        for(i=0; i<Img->width(); i++){

            tmpPix = qGray(Img->pixel(i, j));
            hisMtx[tmpPix]++;
        }
    }
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


void Widget::chooseSource(void)
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Choose Source Image"));

    if (!fileName.isEmpty())
    {
        srcImg.load(fileName);
        srcImg = srcImg.convertToFormat(QImage::Format_RGB32);
        ui->toolButton->setIconSize(QSize(srcImg.width(),srcImg.height()));
        ui->toolButton->setIcon(QPixmap::fromImage(srcImg));

        rsltImg = QImage(srcImg.width(), srcImg.height(), QImage::Format_RGB32);
        ui->pushButton->setEnabled(true);

        CalcHis(&srcImg, mtx);
    }
}




Widget::~Widget()
{
    delete ui;
}
