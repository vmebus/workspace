#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QImage>
#include <QFileDialog>
#include <QPainter>
#include <QColor>
#include <QDebug>

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

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void chooseSource(void);
    void widthChange(int);
    void heightChange(int);
    void symmetricDetection(void);

private:
    Ui::Widget *ui;
    QImage srcImg;
    QImage tmpImg;
    QImage desImg;
    QString fileName;
    bool flg;
    int cnt;
    int width, height;
    int hlfW, hlfH;
    QPainter painter;
    QRect rect;
    QPen pen;
};

#endif // WIDGET_H
