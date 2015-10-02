#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(chooseSource()));
    connect(ui->dial,SIGNAL(valueChanged(int)),this,SLOT(ImgRotated()));
    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(ImgShear()));
    connect(ui->pushButton,SIGNAL(clicked()),this,SLOT(ImgMirrored()));
    connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(resetImg()));
    connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(saveImg()));

    setWindowTitle("Geometric Transform");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::ImgShear(void)
{
    QTransform transform;
    int num;
    bool isXAxis;

    num = ui->horizontalSlider->value();
    isXAxis = ui->radioButton->isChecked();

    if(isXAxis)
    {
        transform.shear(num,0);
    }
    else
    {
        transform.shear(0,num);
    }

    desImg = srcImg.transformed(transform);
    ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));
}

void Widget::ImgRotated(void)
{
    QTransform transform;
    int angle;

    angle = ui->dial->value();
    transform.rotate(angle);
    desImg = srcImg.transformed(transform);
    ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));
}

void Widget::ImgMirrored(void)
{
    bool H,V;

    H = ui->checkBox->isChecked();
    V = ui->checkBox_2->isChecked();

    desImg = tmpImg.mirrored(H,V);
    ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));
    tmpImg = desImg;

}

void Widget::resetImg(void)
{
    desImg = srcImg;
    ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));
}

void Widget::saveImg(void)
{
    desImg.save("D:/resultImg.jpg");
}

void Widget::chooseSource(void)
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Choose Source Image"));

    if (!fileName.isEmpty())
    {
            srcImg.load(fileName);
            desImg = srcImg;
            tmpImg = srcImg;

            ui->toolButton->setIconSize(QSize(srcImg.width(), srcImg.height()));
            ui->toolButton->setIcon(QPixmap::fromImage(srcImg));

            ui->toolButton_2->setIconSize(QSize(desImg.width(), desImg.height()));
            ui->toolButton_2->setIcon(QPixmap::fromImage(desImg));

            ui->dial->setEnabled(true);
            ui->horizontalSlider->setEnabled(true);
            ui->pushButton->setEnabled(true);
            ui->pushButton_2->setEnabled(true);
            ui->pushButton_3->setEnabled(true);

    }

}
