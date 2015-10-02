#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(chooseSource()));
    connect(ui->spinBox,SIGNAL(valueChanged(int)),ui->horizontalSlider,SLOT(setValue(int)));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),ui->spinBox,SLOT(setValue(int)));
    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(genNoise()));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(genNoise()));
    connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(genNoise()));
    connect(ui->radioButton_2,SIGNAL(clicked()),this,SLOT(genNoise()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(meanFilter()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(medianFilter()));
    connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(GaussianFilter()));

    srand(time(NULL));  //for random()
}


void Widget::genNoise()
{
    if (ui->radioButton->isChecked()){
        this->genWhiteNoise();
    }
    else{
        this->genSaltPepperNoise();
    }
}

void Widget::chooseSource()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Choose Source Image"));

    if (!fileName.isEmpty())
    {
        srcImg.load(fileName);
        srcImg = srcImg.convertToFormat(QImage::Format_RGB32);
        ui->toolButton->setIconSize(QSize(srcImg.width(),srcImg.height()));
        ui->toolButton->setIcon(QPixmap::fromImage(srcImg));
        ui->lineEdit->setText(fileName);
        tmpImg = QImage(srcImg);

        ui->pushButton_2->setEnabled(true);
        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        ui->horizontalSlider->setEnabled(true);
        ui->spinBox->setEnabled(true);
        ui->radioButton->setEnabled(true);
        ui->radioButton_2->setEnabled(true);
    }
}

void Widget::genWhiteNoise()
{
    int i,j;
    int var;
    tmpImg = QImage(srcImg);

    for (j=0; j<tmpImg.height();j++){
        for(i=0; i<tmpImg.width();i++){
            var = rand()%(100+1)+1;
            if (var<=ui->spinBox->value()){
                tmpImg.setPixel(i,j,qRgb(255,255,255));
            }
        }
    }
    ui->toolButton->setIconSize(QSize(tmpImg.width(),tmpImg.height()));
    ui->toolButton->setIcon(QPixmap::fromImage(tmpImg));
}

void Widget::genSaltPepperNoise()
{
    int i,j;
    int var;
    tmpImg = QImage(srcImg);

    for (j=0; j<tmpImg.height();j++){
        for(i=0; i<tmpImg.width();i++){
            var = rand()%(100+1)+1;
            if (var<=ui->spinBox->value()){
                if(var&0x1){
                    tmpImg.setPixel(i,j,qRgb(255,255,255));
                }
                else{
                    tmpImg.setPixel(i,j,qRgb(0,0,0));
                }
            }
        }
    }
    ui->toolButton->setIconSize(QSize(tmpImg.width(),tmpImg.height()));
    ui->toolButton->setIcon(QPixmap::fromImage(tmpImg));
}

void Widget::meanFilter()
{
    int i,j;
    int tmpPixel;
    rsltImg = QImage(tmpImg);

    for(j=1; j<tmpImg.height()-1;j++){
        for (i=1; i<tmpImg.width()-1;i++){
            tmpPixel = (qGray(tmpImg.pixel(i-1,j-1))+qGray(tmpImg.pixel(i,j-1))+qGray(tmpImg.pixel(i+1,j-1))
                       +qGray(tmpImg.pixel(i-1,j))+qGray(tmpImg.pixel(i,j))+qGray(tmpImg.pixel(i+1,j))
                       +qGray(tmpImg.pixel(i-1,j+1))+qGray(tmpImg.pixel(i,j+1))+qGray(tmpImg.pixel(i+1,j+1)))/9;
            rsltImg.setPixel(i,j,qRgb(tmpPixel,tmpPixel,tmpPixel));
        }
    }
    ui->toolButton->setIconSize(QSize(rsltImg.width(),rsltImg.height()));
    ui->toolButton->setIcon(QPixmap::fromImage(rsltImg));
}

void Widget::GaussianFilter()
{
    int i,j;
    int tmpPixel;
    rsltImg = QImage(tmpImg);

    for(j=2; j<tmpImg.height()-2; j++){
        for(i=2; i<tmpImg.width()-2; i++){

            tmpPixel = ( 15*qGray(tmpImg.pixel(i,j))+ 12*(qGray(tmpImg.pixel(i-1,j))+qGray(tmpImg.pixel(i,j-1))+qGray(tmpImg.pixel(i+1,j))+qGray(tmpImg.pixel(i,j+1)))

                       +  9*(qGray(tmpImg.pixel(i-1,j-1))+qGray(tmpImg.pixel(i-1,j+1))+qGray(tmpImg.pixel(i+1,j+1))+qGray(tmpImg.pixel(i+1,j-1)))
                     
                       +  4*(qGray(tmpImg.pixel(i-2,j-1))+qGray(tmpImg.pixel(i+2,j-1))+qGray(tmpImg.pixel(i-2,j+1))+qGray(tmpImg.pixel(i+2,j+1))
                           + qGray(tmpImg.pixel(i-1,j-2))+qGray(tmpImg.pixel(i+1,j-2))+qGray(tmpImg.pixel(i-1,j+2))+qGray(tmpImg.pixel(i+1,j+2)))
  +  5*(qGray(tmpImg.pixel(i-2,j))+qGray(tmpImg.pixel(i,j-2))+qGray(tmpImg.pixel(i+2,j))+qGray(tmpImg.pixel(i,j+2)))
                       +  2*(qGray(tmpImg.pixel(i-2,j-2))+qGray(tmpImg.pixel(i+2,j-2))+qGray(tmpImg.pixel(i-2,j+2))+qGray(tmpImg.pixel(i+2,j+2)))

                       )/159;
            rsltImg.setPixel(i,j,qRgb(tmpPixel,tmpPixel,tmpPixel));
        }
    }
    ui->toolButton->setIconSize(QSize(rsltImg.width(),rsltImg.height()));
    ui->toolButton->setIcon(QPixmap::fromImage(rsltImg));
}

void Widget::medianFilter()
{
    int i,j,k;
    unsigned char tmpPixel;
    unsigned char sortTmp[9];

    rsltImg = QImage(tmpImg);

    for(j=1; j<tmpImg.height()-1;j++){
        for (i=1; i<tmpImg.width()-1;i++){

            sortTmp[0] = qGray(tmpImg.pixel(i-1,j-1));
            sortTmp[1] = qGray(tmpImg.pixel(i,j-1));
            sortTmp[2] = qGray(tmpImg.pixel(i+1,j-1));
            sortTmp[3] = qGray(tmpImg.pixel(i-1,j));
            sortTmp[4] = qGray(tmpImg.pixel(i,j));
            sortTmp[5] = qGray(tmpImg.pixel(i+1,j));
            sortTmp[6] = qGray(tmpImg.pixel(i-1,j+1));
            sortTmp[7] = qGray(tmpImg.pixel(i,j+1));
            sortTmp[8] = qGray(tmpImg.pixel(i+1,j+1));

            //bubble sort
            int n=9, newn;
            do{
                newn =0;
                for (k=0;k<n-1;k++){
                    if (sortTmp[k]>sortTmp[k+1]){
                        tmpPixel = sortTmp[k];
                        sortTmp[k] = sortTmp[k+1];
                        sortTmp[k+1] = tmpPixel;
                        newn = k+1;
                    }
                }
                n = newn;
            } while(n>1);
            tmpPixel = sortTmp[4];
            rsltImg.setPixel(i,j,qRgb(tmpPixel,tmpPixel,tmpPixel));
        }
    }
    ui->toolButton->setIconSize(QSize(rsltImg.width(),rsltImg.height()));
    ui->toolButton->setIcon(QPixmap::fromImage(rsltImg));
}
Widget::~Widget()
{
    delete ui;
}
