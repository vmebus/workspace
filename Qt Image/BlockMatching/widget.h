#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QImage>
#include <QFileDialog>
#include <QToolButton>
#include <QDebug>
#include <QPainter>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void chooseImage(const QString &title,QImage *image,QToolButton *button);
    void loadImage(const QString &fileName,QImage *image,QToolButton *button);
    void doFullSearch(int x, int y, int w, int h, int* ansX, int* ansY);
    void doTSS(int x, int y, int w, int h, int* ansX, int* ansY);
    int center(int x, int y, int min);

private slots:
    void choosePatternImg(void);
    void chooseSourceImg(void);
    void fullSearch(void);
    void TSS(void);
    void shift_up(void);
    void shift_down(void);
    void shift_right(void);
    void shift_left(void);
    void reset(void);

private:
    Ui::Widget *ui;
    QImage srcImg;
    QImage tmpImg;
    QImage rsltImg;
    QImage MBImg;
    QPainter painter;
    QPen pen;
    int startX, startY;
    int srchW, srchH, srchMaxW, srchMaxH;
    int ansX, ansY;
};

#endif // WIDGET_H
