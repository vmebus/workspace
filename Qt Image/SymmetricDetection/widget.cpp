#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->toolButton, SIGNAL(clicked()), this, SLOT(chooseSource()));

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            ui->label_3, SLOT(setNum(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            this, SLOT(widthChange(int)));

    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)),
            ui->label_4, SLOT(setNum(int)));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)),
            this, SLOT(heightChange(int)));

    connect(ui->pushButton, SIGNAL(clicked()),
            this, SLOT(symmetricDetection()));

    width = ui->horizontalSlider->value();
    height = ui->horizontalSlider_2->value();
    hlfW = width/2;
    hlfH = height/2;

    flg = false;
    cnt = 0;
}


void Widget::symmetricDetection()
{
    int i, j, ii, jj;
    int sum1, sum2;
    unsigned int result;

    desImg.fill(Qt::black);

    for(j=0; j<(srcImg.height() - height); j++)
    {
        for(i=0; i<(srcImg.width() - width); i++)
        {
            sum1 = 0; sum2 = 0;
            for(jj=0; jj<hlfH; jj++)
            {
                for(ii=0; ii<hlfW; ii++)
                {
                    sum1 += qGray(srcImg.pixel( i+ii, j+jj) );
                    sum2 += qGray(srcImg.pixel( (i+hlfW)+ii, (j+hlfH)+jj) );
                }
            }
            // normalize
            result = abs(sum1-sum2) / (hlfW*hlfW);
            desImg.setPixel(i+hlfW+1, j+hlfH+1, qRgb(result, result, result));
        }
    }

    ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));
}


void Widget::widthChange(int x)
{
    width = x;
    hlfW = width/2;
    flg = true;
}

void Widget::heightChange(int x)
{
    height = x;
    hlfH = height/2;
    flg = true;
}

void Widget::paintEvent(QPaintEvent *event)
{
    if(flg)
    {
        rect = QRect(0, 0, width, height);
        tmpImg = srcImg;

        painter.begin(&tmpImg);
        pen.setWidth(3);
        pen.setColor(qRgb(255, 0, 0));
        painter.setPen(pen);
        painter.drawRect(rect);
        ui->toolButton->setIcon(QPixmap::fromImage(tmpImg));
        painter.end();
        flg = false;
    }
}

Widget::~Widget()
{
    delete ui;
}
void Widget::chooseSource(void)
{
    chooseImage(tr("Choose Source Image"), &srcImg, ui->toolButton);
}


void Widget::chooseImage(const QString &title, QImage *image, QToolButton *button)
{
    fileName = QFileDialog::getOpenFileName(this, title);
    if (!fileName.isEmpty())
    {
        loadImage(fileName, image, button);
    }
}

void Widget::loadImage(const QString &fileName, QImage *image, QToolButton *button)
{
    image->load(fileName);
    image->convertToFormat(QImage::Format_RGB32);
    tmpImg = *image;
    desImg = QImage(QSize(image->width(), image->height()), QImage::Format_RGB32);
    desImg.fill(Qt::black);

    ui->toolButton_2->setIconSize(QSize(desImg.width(), desImg.height()));
    ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));

    button->setIconSize(QSize(image->width(), image->height()));
    button->setIcon(QPixmap::fromImage(*image));

    ui->horizontalSlider->setEnabled(true);
    ui->horizontalSlider_2->setEnabled(true);
    ui->pushButton->setEnabled(true);
    flg = true;
}
