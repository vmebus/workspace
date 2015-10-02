#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(chooseSource()));
    connect(ui->DilationBtn, SIGNAL(clicked()), this, SLOT(Dilation()));
    connect(ui->ErosionBtn, SIGNAL(clicked()), this, SLOT(Erosion()));
    connect(ui->ResetBtn, SIGNAL(clicked()), this, SLOT(ResetImg()));

    // initial mask
    crossMtx[0] = 0;    crossMtx[1] = 255;    crossMtx[2] = 0;
    crossMtx[3] = 255;  crossMtx[4] = 255;    crossMtx[5] = 255;
    crossMtx[6] = 0;    crossMtx[7] = 255;    crossMtx[8] = 0;

    rectMtx[0] = 255; rectMtx[1] = 255; rectMtx[2] = 255;
    rectMtx[3] = 255; rectMtx[4] = 255; rectMtx[5] = 255;
    rectMtx[6] = 255; rectMtx[7] = 255; rectMtx[8] = 255;
}

void Widget::Dilation()
{
    int type = ui->comboBox->currentIndex();

    if(type == cross)
    {
        doDilation(crossMtx);
    }
    else
    {
        doDilation(rectMtx);
    }
    tmpImg = rsltImg;
    ui->toolButton_2->setIcon(QPixmap::fromImage(tmpImg));
}

void Widget::Erosion()
{
    int type = ui->comboBox->currentIndex();

    if(type == cross)
    {
        doErosion(crossMtx, type);
    }
    else
    {
        doErosion(rectMtx, type);
    }
    tmpImg = rsltImg;
    ui->toolButton_2->setIcon(QPixmap::fromImage(tmpImg));
}

void Widget::doDilation(int *mtx)
{
    int i, j;

    for(j=1; j<tmpImg.height()-1; j++)
    {
        for(i=1; i<tmpImg.width()-1; i++)
        {
            if( qGray(tmpImg.pixel(i, j)) != 0 )
            {
                // up row
                if(mtx[0] == 255){
                    rsltImg.setPixel(i-1, j-1, qRgb(255, 255, 255));
                }
                if(mtx[1] == 255){
                    rsltImg.setPixel(i, j-1, qRgb(255, 255, 255));
                }
                if(mtx[2] == 255){
                    rsltImg.setPixel(i+1, j-1, qRgb(255, 255, 255));
                }
                // middle row
                if(mtx[3] == 255){
                    rsltImg.setPixel(i-1, j, qRgb(255, 255, 255));
                }
                if(mtx[4] == 255){
                    rsltImg.setPixel(i, j, qRgb(255, 255, 255));
                }
                if(mtx[5] == 255){
                    rsltImg.setPixel(i+1, j, qRgb(255, 255, 255));
                }
                // down row
                if(mtx[6] == 255){
                    rsltImg.setPixel(i-1, j+1, qRgb(255, 255, 255));
                }
                if(mtx[7] == 255){
                    rsltImg.setPixel(i, j+1, qRgb(255, 255, 255));
                }
                if(mtx[8] == 255){
                    rsltImg.setPixel(i+1, j+1, qRgb(255, 255, 255));
                }
            }
        }
    }
}

void Widget::doErosion(int *mtx, int type)
{
    int i, j;

    if(type == cross)
    {
        for(j=1; j<tmpImg.height()-1; j++)
        {
            for(i=1; i<tmpImg.width()-1; i++)
            {
                if(qGray(tmpImg.pixel(i, j-1)) == mtx[1] && qGray(tmpImg.pixel(i-1, j)) == mtx[3]
                   && qGray(tmpImg.pixel(i, j)) == mtx[4] && qGray(tmpImg.pixel(i+1, j)) == mtx[5]
                   && qGray(tmpImg.pixel(i, j+1)) == mtx[7])
                {
                    rsltImg.setPixel(i, j, qRgb(255, 255, 255));
                }
                else
                {
                    rsltImg.setPixel(i, j, qRgb(0, 0, 0));
                }
            }
        }
    }
    else
    {
        for(j=1; j<tmpImg.height()-1; j++)
        {
            for(i=1; i<tmpImg.width()-1; i++)
            {
                if(qGray(tmpImg.pixel(i-1, j-1)) == mtx[0] && qGray(tmpImg.pixel(i, j-1)) == mtx[1]
                   && qGray(tmpImg.pixel(i+1, j-1) )== mtx[2] && qGray(tmpImg.pixel(i-1, j)) == mtx[3]
                   && qGray(tmpImg.pixel(i, j)) == mtx[4] && qGray(tmpImg.pixel(i+1, j)) == mtx[5]
                   && qGray(tmpImg.pixel(i-1, j+1)) == mtx[6] && qGray(tmpImg.pixel(i, j+1)) == mtx[7]
                   && qGray(tmpImg.pixel(i+1, j+1)) == mtx[8])
                {
                    rsltImg.setPixel(i, j, qRgb(255, 255, 255));
                }
                else
                {
                    rsltImg.setPixel(i, j, qRgb(0, 0, 0));
                }
            }
        }
    }

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

        getBinaryImg();

        ui->toolButton->setIconSize(QSize(srcImg.width(),
                                          srcImg.height()));
        ui->toolButton->setIcon(QPixmap::fromImage(binImg));

        tmpImg = binImg;

        rsltImg = QImage(QSize(srcImg.width(), srcImg.height()), QImage::Format_RGB32);
        rsltImg.fill(0);
        ui->toolButton_2->setIconSize(QSize(rsltImg.width(), rsltImg.height()));
        ui->comboBox->setEnabled(true);
        ui->DilationBtn->setEnabled(true);
        ui->ErosionBtn->setEnabled(true);
        ui->ResetBtn->setEnabled(true);
    }
}

void Widget::getBinaryImg(void)
{
    int i, j;
    int tmpPix;
    binImg = srcImg;

    for(j=0; j<srcImg.height(); j++){
        for(i=0; i<srcImg.width(); i++){
            tmpPix = ( qGray(srcImg.pixel(i, j)) > 128) ? 255 : 0;
            binImg.setPixel(i, j, qRgb(tmpPix, tmpPix, tmpPix));
        }
    }
}

void Widget::ResetImg()
{
    tmpImg = binImg;
    rsltImg.fill(0);
    ui->toolButton_2->setIcon(QPixmap::fromImage(rsltImg));
}

Widget::~Widget()
{
    delete ui;
}
