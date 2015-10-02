#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QImage>
#include <QFileDialog>
#include <QTransform>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
//    void chooseImage(const QString &title, QImage *image, QToolButton *button);
//    void loadImage(const QString &fileName, QImage *image, QToolButton *button);

private slots:
    void chooseSource(void);
    void ImgShear(void);
    void ImgMirrored(void);
    void ImgRotated(void);
    void resetImg(void);
    void saveImg(void);

private:
    QImage srcImg;
    QImage tmpImg;
    QImage desImg;

    Ui::Widget *ui;
};

#endif // WIDGET_H
