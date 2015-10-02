#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QImage>
#include <QFileDialog>
#include <QLabel>
#include "BitField.h"

namespace Ui {
    class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void chooseImage(const QString &title, QImage *image, QImage *desImg,
                      QToolButton *button, QToolButton *desButton, QLabel *label);

     void loadImage(const QString &fileName, QImage *image, QImage *desImg,
                    QToolButton *button, QToolButton *desButton, QLabel *label);
 private slots:
     void chooseSource_1(void);
     void chooseSource_2(void);
     void chooseSource_3(void);
     void doLBP(QImage *image, QImage *desImg, QToolButton *desButton, QLabel *label);

private:
    Ui::Widget *ui;
    QImage srcImg_1;
    QImage LBPImg_1;
    QImage srcImg_2;
    QImage LBPImg_2;
    QImage srcImg_3;
    QImage LBPImg_3;
};

#endif // WIDGET_H
