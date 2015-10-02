#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QFileDialog>
#include <QToolButton>

enum MaskType{ cross, rect};

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void doDilation(int* mtx);
    void doErosion(int* mtx, int type);
    void getBinaryImg(void);

private slots:
    void chooseSource(void);
    void Erosion(void);
    void Dilation(void);
    void ResetImg(void);

private:
    Ui::Widget *ui;
    QImage srcImg;
    QImage tmpImg;
    QImage rsltImg;
    QImage binImg;
    int crossMtx[9];
    int rectMtx[9];
};

#endif // WIDGET_H
