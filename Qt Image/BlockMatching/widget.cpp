#include "widget.h"
#include "ui_widget.h"

const int SEARCH_AREA_FAC = 2;
const int SKIP = 20;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(choosePatternImg()));
    connect(ui->toolButton_2,SIGNAL(clicked()),this,SLOT(chooseSourceImg()));
    connect(ui->FS_Btn,SIGNAL(clicked()),this,SLOT(fullSearch()));
    connect(ui->TSS_Btn,SIGNAL(clicked()),this,SLOT(TSS()));
    connect(ui->Reset_Btn,SIGNAL(clicked()),this,SLOT(reset()));
    connect(ui->upBtn,SIGNAL(clicked()),this,SLOT(shift_up()));
    connect(ui->dnBtn,SIGNAL(clicked()),this,SLOT(shift_down()));
    connect(ui->ltBtn,SIGNAL(clicked()),this,SLOT(shift_left()));
    connect(ui->rtBtn,SIGNAL(clicked()),this,SLOT(shift_right()));

    pen.setWidth(3);
    startX = 0;
    startY = 0;
    ansX = 0;
    ansY = 0;
}

void Widget::reset(void)
{
    tmpImg = srcImg;
    rsltImg = srcImg;
    ui->toolButton_2->setIcon(QPixmap::fromImage(tmpImg));
}

void Widget::shift_up(void)
{
    tmpImg = rsltImg;
    startY = (startY-SKIP)>0 ? startY-=SKIP : 0;

    pen.setColor(qRgb(255,0,0));
    pen.setStyle(Qt::SolidLine);
    painter.begin(&tmpImg);
    painter.setPen(pen);
    painter.drawRect(startX,startY,srchMaxW,srchMaxH);

    pen.setStyle(Qt::DashLine);
    pen.setColor(qRgb(255, 255, 0));
    painter.setPen(pen);
    painter.drawRect(startX+MBImg.width()/2+MBImg.width()/4,startY+MBImg.width()/2+MBImg.width()/4,srchMaxW,srchMaxH);
    painter.end();

    painter.begin(&rsltImg);
    painter.end();

    ui->toolButton_2->setIcon(QPixmap::fromImage(tmpImg));
}

void Widget::shift_down(void)
{
    tmpImg = rsltImg;
    startY = (startY+SKIP+srchMaxH) <srcImg.height() ? startY+=SKIP : srcImg.height()-srchMaxH;

    pen.setColor(qRgb(255,0,0));
    pen.setStyle(Qt::SolidLine);
    painter.begin(&tmpImg);
    painter.setPen(pen);
    painter.drawRect(startX,startY,srchMaxW,srchMaxH);

    pen.setStyle(Qt::DashLine);
    pen.setColor(qRgb(255,0,0));
    painter.setPen(pen);
    painter.drawRect(startX+MBImg.width()/2+MBImg.width()/4,startY+MBImg.width()/2+MBImg.width()/4,srchMaxW,srchMaxH);
    painter.end();

    painter.begin(&rsltImg);
    painter.end();

    ui->toolButton_2->setIcon(QPixmap::fromImage(tmpImg));
}


void Widget::shift_left(void)
{
    tmpImg = rsltImg;
    startX = (startX-SKIP) > 0 ? startX-=SKIP : 0;

    pen.setColor(qRgb(255,0,0));
    pen.setStyle(Qt::SolidLine);
    painter.begin(&tmpImg);
    painter.setPen(pen);
    painter.drawRect(startX,startY,srchMaxW,srchMaxH);

    pen.setStyle(Qt::DashLine);
    pen.setColor(qRgb(255, 255, 0));
    painter.setPen(pen);
    painter.drawRect(startX+MBImg.width()/2+MBImg.width()/4,startY+MBImg.width()/2+MBImg.width()/4,srchMaxW,srchMaxH);
    painter.end();

    painter.begin(&rsltImg);
    painter.end();

    ui->toolButton_2->setIcon(QPixmap::fromImage(tmpImg));
}
void Widget::shift_right(void)
{
    tmpImg = rsltImg;
    startX = (startX+SKIP + srchMaxW) < srcImg.width()
             ? startX+=SKIP : srcImg.width()-srchMaxW;
    pen.setColor(qRgb(255,0,0));
    pen.setStyle(Qt::SolidLine);
    painter.begin(&tmpImg);
    painter.setPen(pen);
    painter.drawRect(startX,startY,srchMaxW,srchMaxH);

    pen.setStyle(Qt::DashLine);
    pen.setColor(qRgb(255, 255, 0));
    painter.setPen(pen);
    painter.drawRect(startX+MBImg.width()/2+MBImg.width()/4,startY+MBImg.width()/2+MBImg.width()/4,srchMaxW,srchMaxH);
    painter.end();

    painter.begin(&rsltImg);
    painter.end();

    ui->toolButton_2->setIcon(QPixmap::fromImage(tmpImg));
}
void Widget::fullSearch(void)
{
    doFullSearch(startX, startY, srchMaxW, srchMaxH, &ansX, &ansY);

    painter.begin(&rsltImg);
    pen.setColor(qRgb(255, 100, 100));
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    painter.drawRect(ansX, ansY, MBImg.width(), MBImg.height());
    painter.end();

    ui->toolButton_2->setIcon(QPixmap::fromImage(rsltImg));
}
void Widget::doFullSearch(int x, int y, int w, int h, int* ansX, int* ansY)
{
    int i,ii,j,jj,progressV;
    unsigned int diff,tmp,MyMin=(~0),cnt=0;

    for(j=y;j<(y+h)-MBImg.height();j++){
        for(i=x; i<(x+w)-MBImg.width(); i++){
            diff =0;
            for(jj=0;jj<MBImg.height();jj++){
                for(ii=0;ii<MBImg.width();ii++){
                    tmp = abs(qGray(srcImg.pixel(i+ii,j+jj))-qGray((MBImg.pixel(ii,jj))));
                    diff += (tmp*tmp); // SSD
                }
            }
            if(diff<MyMin){
                MyMin = diff;
                *ansX = i;
                *ansY = j;
            }
            progressV = (100*++cnt)/((w-MBImg.width())*(h-MBImg.height()));
            ui->progressBar->setValue(progressV);
        }
    }
    qDebug() << *ansX << *ansY << MyMin << "Full Search finished!" << endl;
}

void Widget::TSS(void)
{
    doTSS(startX + MBImg.width()/2 + MBImg.width()/4,
          startY+ MBImg.height()/2 + MBImg.height()/4,
          srchW, srchH, &ansX, &ansY);

    painter.begin(&rsltImg);
    pen.setColor(qRgb(255, 100, 100));
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    painter.drawRect(ansX, ansY, MBImg.width(), MBImg.height());
    painter.end();

    ui->toolButton_2->setIcon(QPixmap::fromImage(rsltImg));
}
void Widget::doTSS(int x, int y, int w, int h, int* ansX, int* ansY)
{
    int i,ii,j,jj,progressV;
    unsigned int diff,tmp,MyMin=(~0),cnt;
    int ninumNm =0, xCntl, yCntl,skip_x, skip_y;

    // step1:
    skip_y = h/4;
    skip_x = w/4;

    for(cnt=1,yCntl=0,j=y ;yCntl<3;yCntl++,j+skip_y){
        for(xCntl=0,i=x ;xCntl<3;xCntl++,i+skip_x){
            diff =0;
            for(jj=0;jj<MBImg.height();jj++){
                for(ii=0;ii<MBImg.width();ii++){
                    tmp = abs(qGray(srcImg.pixel(i+ii,j+jj))-qGray((MBImg.pixel(ii,jj))));
                    diff += (tmp*tmp); // SSD
                }
            }
            if(diff<MyMin){
                MyMin = diff;
                *ansX = i;
                *ansY = j;
                ninumNm = cnt;
            }
            cnt++;
            progressV += 4;
            ui->progressBar->setValue(progressV);
        }
    }

	//step 2
    y = (*ansY > h/8) ? (*ansY - h/8) : 0;
    x = (*ansX > w/8) ? (*ansX - w/8) : 0;

    skip_x = h/8;
    skip_y = w/8;

    for(cnt=10,yCntl=0,j=y ;yCntl<3;yCntl++,j+skip_y){
        for(xCntl=0,i=x ;xCntl<3;xCntl++,i+skip_x){
            diff =0;
            for(jj=0;jj<MBImg.height();jj++){
                for(ii=0;ii<MBImg.width();ii++){
                    tmp = abs(qGray(srcImg.pixel(i+ii,j+jj))-qGray((MBImg.pixel(ii,jj))));
                    diff += (tmp*tmp); // SSD
                }
            }
            if(diff<MyMin){
                MyMin = diff;
                *ansX = i;
                *ansY = j;
                ninumNm = cnt;
            }
            cnt++;
            progressV += 4;
            ui->progressBar->setValue(progressV);
        }
    }

    y = (*ansY > h/16) ? (*ansY - h/16) : 0;
    x = (*ansX > w/16) ? (*ansX - w/16) : 0;

    skip_x = h/16;
    skip_y = w/16;

    for(cnt=18,yCntl=0,j=y ;yCntl<3;yCntl++,j+skip_y){
        for(xCntl=0,i=x ;xCntl<3;xCntl++,i+skip_x){
            diff =0;
            for(jj=0;jj<MBImg.height();jj++){
                for(ii=0;ii<MBImg.width();ii++){
                    tmp = abs(qGray(srcImg.pixel(i+ii,j+jj))-qGray((srcImg.pixel(ii,jj))));
                    diff+=(tmp+tmp);
                }
            }
            if(diff<MyMin){
                MyMin = diff;
                *ansX = i;
                *ansY = j;
                ninumNm = cnt;
            }
            cnt++;
            progressV += 4;
            ui->progressBar->setValue(progressV);
        }
    }

    qDebug() << *ansX << *ansY << MyMin << "3 step search finished!" << endl;
}



void Widget::choosePatternImg(void)
{
    chooseImage(tr("Choose Pattern Image"),&MBImg,ui->toolButton);
    srchW = MBImg.width()*SEARCH_AREA_FAC;
    srchH = MBImg.height()*SEARCH_AREA_FAC;
    srchMaxW = MBImg.width()*SEARCH_AREA_FAC+(MBImg.width()/2+MBImg.width()/4)*2;
    srchMaxH = MBImg.height()*SEARCH_AREA_FAC+(MBImg.height()/2+MBImg.height()/4)*2;
    ui->toolButton_2->setEnabled(true);
}

void Widget::chooseSourceImg(void)
{
    chooseImage(tr("Choose Source Image"),&srcImg,ui->toolButton_2);
    tmpImg = srcImg;
    rsltImg = srcImg;
    pen.setColor(qRgb(255,0,0));
    pen.setStyle(Qt::SolidLine);
    painter.begin(&tmpImg);
    painter.setPen(pen);
    painter.drawRect(startX,startY,srchMaxW,srchMaxH);

    pen.setColor(qRgb(255,0,0));
    pen.setStyle(Qt::DashLine);
    painter.setPen(pen);
    painter.drawRect(startX+MBImg.width()/2+MBImg.width()/4,startY+MBImg.width()/2+MBImg.width()/4,srchMaxW,srchMaxH);
    painter.end();

    ui->toolButton_2->setIcon(QPixmap::fromImage(tmpImg));
    ui->upBtn->setEnabled(true);
    ui->dnBtn->setEnabled(true);
    ui->rtBtn->setEnabled(true);
    ui->ltBtn->setEnabled(true);
    ui->FS_Btn->setEnabled(true);
    ui->TSS_Btn->setEnabled(true);
    ui->Reset_Btn->setEnabled(true);
}

void Widget::chooseImage(const QString &title, QImage *image,
                                QToolButton *button)
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
}
Widget::~Widget()
{
    delete ui;
}
