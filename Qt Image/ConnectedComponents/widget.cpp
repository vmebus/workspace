#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
        QWidget(parent),
        ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(chooseSource()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(getBinaryImg()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(getCCL()));

    // initial link[]
    for(int i=1; i<=MAX_COMPONENTS; i++){
        link[i-1] = i;
    }
}

void Widget::getBinaryImg()
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
    ui->toolButton_2->setEnabled(true);
    ui->toolButton_2->setIconSize(QSize(binImg.width(), binImg.height()));
    ui->toolButton_2->setIcon(QPixmap::fromImage(binImg));
    ui->pushButton_2->setEnabled(true);
}

void Widget::getCCL()
{
    srand(time(NULL)); // for random()
    rsltImg = binImg;
    int labels;

    labels = this->getConnectedComponentLabeling(); // first pass

    if( labels >= MAX_COMPONENTS ){
        QMessageBox msgBox;
        msgBox.setText("The document has been modified.");
        msgBox.exec();
        return;
    }
    resetLabel(link); // second pass

    // draw labels
    labels = countLabelNm();

    QVariant var;
    var = labels;
    QString resultStr;
    resultStr = "Total " + var.toString() + " components were labeled!";
    QMessageBox msgBox;
    msgBox.setText(resultStr);
    msgBox.exec();
    ui->toolButton_3->setEnabled(true);
    ui->toolButton_3->setIconSize(QSize(rsltImg.width(), rsltImg.height()));
    ui->toolButton_3->setIcon(QPixmap::fromImage(rsltImg));
}



int Widget::getConnectedComponentLabeling()
{
    int i, j;
    int currlabel = 1;
    int label;
    int a[4];
    for(j=1; j<rsltImg.height()-1; j++){
        for(i=1; i<rsltImg.width()-1; i++){
            // 8 connected
            if( qGray(rsltImg.pixel(i,j)) != 0 )
            {
                a[0] = qGray(rsltImg.pixel(i-1,j-1));
                a[1] = qGray(rsltImg.pixel(i,j-1));
                a[2] = qGray(rsltImg.pixel(i+1,j-1));
                a[3] = qGray(rsltImg.pixel(i-1,j));

                label = MyMin(a);

                if(label != 0 && label != 255){
                    rsltImg.setPixel(i, j, qRgb(label, label, label));
                }
                else{
                    rsltImg.setPixel(i, j, qRgb(currlabel, currlabel, currlabel));
                    currlabel++;
                }
            }
        }
    }
    return (currlabel-1);
}

int Widget::MyMin(int *v)
{
    int i;
    int index = 88; // error code
    unsigned short min = (500);

    for ( i = 1; i < 4; i++ ){
        if(v[i] < min && v[i] !=0)
        {
            min = v[i];
            index = i;
        }
    }

    if(index == 88){
        return 0;
    }
    else{
        for(i=0; i<4; i++){
            if(v[i] !=0){
                link[v[i]-1] = link[v[index]-1];
            }
        }
        return v[index];
    }
}


void Widget::resetLabel(unsigned char* link)
{
    int i, j;
    int tmpPix;
    for(j=0; j<rsltImg.height(); j++)
    {
        for(i=0; i<rsltImg.width(); i++)
        {
            if( qGray(rsltImg.pixel(i,j)) != 0 )
            {
                tmpPix = link[qGray(rsltImg.pixel(i,j))-1];
                rsltImg.setPixel(i,j, qRgb(tmpPix, tmpPix, tmpPix));
            }
        }
    }
}


int Widget::countLabelNm()
{
    int i, j, k;
    int buffer[255];
    int cnt = 0;

    // find how many labels.
    for(j=0; j<rsltImg.height()-1; j++){
        for(i=0; i<rsltImg.width()-1; i++){
            if(qGray(rsltImg.pixel(i,j)) != 0){
                if(cnt == 0){
                    buffer[cnt++] = qGray(rsltImg.pixel(i,j));
                }
                else{
                    for(k=0; k<cnt; k++){
                        if(buffer[k] == qGray(rsltImg.pixel(i,j))){
                            break;
                        }
                    }
                    if(k == cnt){
                        buffer[cnt++] = qGray(rsltImg.pixel(i,j));
                    }
                }
            }
        }
    }

    // draw all labels.
    unsigned char red, green, blue;

    for(k=0; k<cnt; k++)
    {
        red = rand()%256; // 0~255
        green = rand()%256;
        blue = rand()%256;

        for(j=0; j<rsltImg.height()-1; j++)
        {
            for(i=0; i<rsltImg.width()-1; i++)
            {
                if(qGray(rsltImg.pixel(i,j)) == buffer[k])
                {
                    rsltImg.setPixel(i, j, qRgb(red, green, blue));
                }
            }
        }
    }

    return cnt;
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
    }
}


Widget::~Widget()
{
    delete ui;
}
