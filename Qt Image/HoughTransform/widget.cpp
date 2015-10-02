#include "widget.h"
#include "ui_widget.h"
#include <cmath>

#define PI 3.14159265
//sin() method -> sin(degree*Pi/180)
#define ImgW 300
#define ImgH 300
#define thetaSkip 3


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked()),this, SLOT(houghTransform()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(resetParameters()));
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(setThetaNoise()));
    connect(ui->spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(setRhoNoise()));
    connect(ui->spinBox_3,SIGNAL(valueChanged(int)),this,SLOT(setThreshold()));

    ThetaNoise = ui->spinBox->value();
    RhoNoise = ui->spinBox_2->value();
    maxTh = ui->spinBox_3->value();

    pen.setColor(Qt::white);
    pen.setWidth(3);

    srcImg = QImage(ImgW,ImgH,QImage::Format_RGB32);
    srcImg.fill(Qt::black);

    ui->label->setPixmap(QPixmap::fromImage(srcImg));

    H = 180;  //theta
    W = 430;  //rho

    pointCnt = 0;
    lineCnt = 0;
    acc = new unsigned short [H*(W*2)];
    memset(acc,0,H*(W*2));
}

void Widget::setThetaNoise()
{
    ThetaNoise = ui->spinBox->value();
}

void Widget::setRhoNoise()
{
    RhoNoise = ui->spinBox_2->value();
}

void Widget::setThreshold()
{
    maxTh = ui->spinBox_3->value();
}

void Widget::resetParameters()
{
    delete [] acc;
    pen.setColor(Qt::white);
    pen.setWidth(3);

    H = 180;  //theta
    W = 430;  //rho

    ThetaNoise = ui->spinBox->value();
    RhoNoise = ui->spinBox_2->value();
    maxTh = ui->spinBox_3->value();

    pointCnt = 0;
    lineCnt = 0;

    rsltPoint.clear();
    hfPoint.clear();

    acc = new unsigned short [H*(W*2)];
    memset(acc,0,H*(W*2));

    srcImg.fill(Qt::black);

    ui->label->setPixmap(QPixmap::fromImage(srcImg));

}

void Widget::houghTransform(void)
{
    int p,i,j;
    int theta = 0, rho =0;
    int tmpRhoNoise, tmpThetaNoise;
    //unsigned int BasePos;

    //accumulate all results
    for(p=0;p < pointCnt; p++){
        for (theta=0; theta <H; theta+=thetaSkip){
            rho = hfPoint.at(p).x()*cos(theta*PI/180)+hfPoint.at(p).y()*sin(theta*PI/180);
            rho = (rho<0) ? (-rho) : (rho+W);
            acc[rho+theta*(W*2)]++;
        }
    }

    //find line
    bool continueFlg;
    do{
        maxValue = 0;
        continueFlg = false;

        for(j=0; j<H;j++){
            for(i=0;i<(W*2);i++){
                if(acc[i+j*(W*2)]>maxTh && acc[i+j*(W*2)]>maxValue){
                    maxValue = acc[i+j*(W*2)];
                    rho = i;
                    theta = j;
                    continueFlg = true;
                }
            }
        }

        //non-maximum supression
        if(continueFlg)
        {
            lineCnt++;
            rsltPoint.append(QPoint(rho,theta));
            qDebug() <<"line "<<rho-W<<""<<theta;
            tmpThetaNoise = ThetaNoise;
            tmpRhoNoise = RhoNoise;

            if((rho+RhoNoise) > (W*2)-1){
                tmpRhoNoise = (W*2)-rho;
            }
            if ((rho-RhoNoise) < 0){
                tmpRhoNoise = rho;
            }
            for(j=0;j<H;j++){
                for(i=rho-tmpRhoNoise;i<rho+tmpRhoNoise;i++){
                    acc[i+j*(W*2)] = 0;
                }
            }
            if((theta+ThetaNoise) > H-1){
                tmpThetaNoise = H - theta;
            }
            if((theta-ThetaNoise)<0){
                tmpThetaNoise = theta;
            }
            for(j=theta-tmpThetaNoise; j<theta+tmpThetaNoise;j++){
                for(i=0;i<W*2;i++){
                    acc[i+j*(W*2)]=0;
                }
            }
        }
        }while(continueFlg);

        qDebug() << "lineCnt" << lineCnt;

        //Draw result
        int x,y;
        pen.setColor(Qt::darkRed);
        pen.setWidth(1);
        painter.begin(&srcImg);

        for(i=0;i<lineCnt;i++){
            rho = (rsltPoint.at(i).x()>W) ? (rsltPoint.at(i).x()-W) : (-rsltPoint.at(i).x());
            theta = rsltPoint.at(i).y();

            if(theta>45 && theta<135){
                for(x=0;x<ImgW;x++){
                    y=(rho-x*cos(theta*PI/180))/sin(theta*PI/180);
                    if(y<0 || y>ImgH){
                        continue;
                    }
                    else{
                        painter.setPen(pen);
                        painter.drawPoint(x,y);
                    }
                }
            }
            else{
                for(y=0;x<ImgH;y++){
                    x=(rho-y*sin(theta*PI/180))/cos(theta*PI/180);
                    if(x<0 || x>ImgW){
                        continue;
                    }
                    else{
                        painter.setPen(pen);
                        painter.drawPoint(x,y);
                    }
                }
            }
        }

    painter.end();
    ui->label->setPixmap(QPixmap::fromImage(srcImg));
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
    {
        point = event->pos();
        hfPoint.append(point);
        pointCnt++;
        painter.begin(&srcImg);
        painter.setPen(pen);
        painter.drawPoint(point);
        painter.end();
        ui->label->setPixmap(QPixmap::fromImage(srcImg));
    }
}




Widget::~Widget()
{
    delete ui;
}
