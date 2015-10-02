#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    outputImg = QImage(500,500,QImage::Format_RGB32);
    outputImg.fill(qRgb(255,255,255));
    point = QPoint(350,70);
    rect = QRect(0,0,150,180);

    //linear gradient setting
    linearGrad = QLinearGradient(QPointF(0,0),QPointF(500,500));
    linearGrad.setColorAt(0.1,Qt::blue);
    linearGrad.setColorAt(0.2,Qt::yellow);
    linearGrad.setColorAt(0.6,Qt::blue);
    linearGrad.setColorAt(1,Qt::white);

    //radial gradient setting
    radialGrad = QRadialGradient(QPointF(250,250),300);
    radialGrad.setColorAt(0,Qt::red);
    radialGrad.setColorAt(1,Qt::black);

    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(setPenWidth(int)));
    connect(ui->comboBox_2,SIGNAL(currentIndexChanged(int)),this,SLOT(setBrushStyle(int)));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(setPenStyle(int)));
}

void Widget::setPenWidth(int w)
{
    pen.setWidth(w);
    outputImg.fill(qRgb(255,255,255));
}

void Widget::setPenStyle(int s)
{
    Qt::PenStyle style;

    switch(s)
    {
        case SolidLine:
            style = Qt::SolidLine;
        break;

        case DashLine:
            style = Qt::DashLine;
        break;

        case DotLine:
            style = Qt::DotLine;
        break;

        case DashDotLine:
            style = Qt::DashDotLine;
        break;

        case DashDotDotLine:
            style = Qt::DashDotDotLine;
        break;
    }
    pen.setStyle(style);
    outputImg.fill(qRgb(255,255,255));
}

void Widget::setBrushStyle(int s)
{
    Qt::BrushStyle style;

    switch(s)
    {
        case NoBrush:
            style = Qt::NoBrush;
        break;

        case SolidPattern:
            style = Qt::SolidPattern;
            brush.setColor(Qt::green);
        break;

        case LinearGradientPattern:
            style = Qt::LinearGradientPattern;
            brush = QBrush(linearGrad);
        break;

        case RadialGradientPattern:
            style = Qt::RadialGradientPattern;
            brush = QBrush(radialGrad);
        break;

        case TexturePattern:
            style = Qt::TexturePattern;
            brush.setTexture(QPixmap(":/image/eyes.jpg"));
        break;
    }
    brush.setStyle(style);
    outputImg.fill(qRgb(255,255,255));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    painter.begin(&outputImg);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    painter.drawLine(100,30,450,30);
    QPainterPath path;
    path.moveTo(200,200);
    path.lineTo(200,150);
    path.lineTo(250,200);
    path.cubicTo(250,0,80,200,100,200);
    painter.drawPath(path);
    painter.setBrush(brush);
    painter.translate(100,150);
    painter.rotate(30.0);
    painter.drawRect(rect);
    painter.resetTransform();
    pen.setColor(qRgb(255,100,100));
    painter.setPen(pen);
    painter.drawEllipse(250,250,200,200);
    painter.drawPoint(QPoint(50,50));
    painter.drawText(point,tr("Image Processing by Qt!"));
    painter.end();
    ui->label->setPixmap(QPixmap::fromImage(outputImg));
}
