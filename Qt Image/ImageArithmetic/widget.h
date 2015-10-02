#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QImage>
#include <QFileDialog>

enum Logic{

    ADD=1, SUB, OR, NOR, AND, NAND, XOR, NXOR
};

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
    void LogicOperator(QImage *srcImg, QImage *srcImg_2, QImage *output, int Method);

private slots:
    void chooseSource(void);
    void chooseSource2(void);
    void calcResult(int);

private:
    QImage srcImg;
    QImage srcImg_2;
    QImage desImg;
    Ui::Widget *ui;
};

#endif // WIDGET_H
