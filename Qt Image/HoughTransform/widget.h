#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QLabel>
#include <QPainter>
#include <QPen>
#include <QMouseEvent>
#include <QPoint>
#include <QDebug>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *event);

private slots:
    void houghTransform(void);
    void resetParameters(void);
    void setThetaNoise(void);
    void setRhoNoise(void);
    void setThreshold(void);

private:
    Ui::Widget *ui;
    QImage srcImg;
    QPainter painter;
    QPen pen;
    QPoint point;
    QList<QPoint> hfPoint;
    QList<QPoint> rsltPoint;
    unsigned short pointCnt;
    unsigned short lineCnt;
    unsigned short *acc;
    unsigned short H,W;
    unsigned short ThetaNoise,RhoNoise;
    unsigned short maxTh,maxValue;

};

#endif // WIDGET_H
