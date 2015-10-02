#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QToolButton>
#include <QPainter>

const int hisSize = 256;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    void CalcHis(QImage *srcImg, unsigned int* hisMtx);
    void CalcCDF(unsigned int* hisMtx, unsigned int* CDFMtx);
    int getThreshold(QImage *img, unsigned int* hisMtx, unsigned int* CDFMtx);
    void getBinaryImg(QImage *srcImg, QImage *rsltImg, int TH);

private slots:
    void chooseSource(void);
    void Otsu(void);

private:
    Ui::Widget *ui;

    QImage srcImg;
    QImage rsltImg;
    unsigned int mtx[hisSize];
    unsigned int CDFMtx[hisSize];
};

#endif // WIDGET_H
