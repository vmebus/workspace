#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QImage>
#include <QFileDialog>
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
    void chooseImage(const QString &title, QImage *image, QToolButton *button);
    void loadImage(const QString &fileName, QImage *image, QToolButton *button);
    void addComboList();
    void getBitPlane();

private slots:
    void chooseSource();
    void showBitPlane(int index);

private:
    Ui::Widget *ui;
    QImage srcImg;
    QImage bit0Img;
    QImage bit1Img;
    QImage bit2Img;
    QImage bit3Img;
    QImage bit4Img;
    QImage bit5Img;
    QImage bit6Img;
    QImage bit7Img;

};

#endif // WIDGET_H
