#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QPainter>

namespace Ui {
class Widget;
}

enum penStyle {
    SolidLine,
    DashLine,
    DotLine,
    DashDotLine,
    DashDotDotLine
};

enum brushStyle {
    NoBrush,
    SolidPattern,
    LinearGradientPattern,
    RadialGradientPattern,
    TexturePattern
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void setPenWidth(int);
    void setPenStyle(int);
    void setBrushStyle(int);

private:
    Ui::Widget *ui;
    QImage  outputImg;
    QPainter painter;
    QPoint point;
    QRect rect;
    QPen pen;
    QBrush brush;
    QLinearGradient linearGrad;
    QRadialGradient radialGrad;
};

#endif // WIDGET_H
