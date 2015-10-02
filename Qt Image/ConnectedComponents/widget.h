#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QToolButton>
#include <QFileDialog>
#include "time.h"
#include <QMessageBox>
#include <QVariant>

#define MAX_COMPONENTS 100

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

    int getConnectedComponentLabeling(void);
    void findEqualLabel(unsigned char *link);
    void resetLabel(unsigned char *link);
    int countLabelNm(void);
    int MyMin(int *v);

private slots:
    void chooseSource(void);
    void getBinaryImg(void);
    void getCCL(void);

private:
    QImage srcImg;
    QImage binImg;
    QImage rsltImg;
    unsigned char link[MAX_COMPONENTS];

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
