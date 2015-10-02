#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QToolButton>
#include <QPainter>

const int hisSize = 256;
const int H = hisSize;
const int W = hisSize;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);

    void CalcHis(QImage *srcImg, QImage *drawImg, unsigned int* hisMtx, QToolButton *button);
    void CalcCDF(unsigned int* hisMtx, unsigned int* CDFMtx);
    void ImgEqualization(QImage *srcImg, QImage *desImg, unsigned int* CDFMtx);

    ~Widget();

private slots:
    void chooseSource(void);
    void histEq(void);

private:
    Ui::Widget *ui;

    QImage srcImg;
    QImage rsltImg;
    QImage hisImg;
    QImage hisEqImg;
    QPainter painter;
    unsigned int mtx[hisSize];
    unsigned int mtxEq[hisSize];
    unsigned int CDFMtx[hisSize];

};

#endif // WIDGET_H
