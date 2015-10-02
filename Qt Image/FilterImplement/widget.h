#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QFileDialog>
#include <QLabel>
#include <QToolBar>
#include "time.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void genWhiteNoise(void);
    void genSaltPepperNoise(void);

private slots:
    void chooseSource(void);
    void meanFilter(void);
    void medianFilter(void);
    void GaussianFilter(void);
    void genNoise(void);

private:
    Ui::Widget *ui;
    QImage srcImg;
    QImage tmpImg;
    QImage rsltImg;

};

#endif // WIDGET_H
