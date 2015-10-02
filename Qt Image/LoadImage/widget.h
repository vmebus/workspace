#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QToolButton>
#include <QImage>
#include <QFileDialog>

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

private slots:
    void chooseSource();

private:
    QImage srcImg;
    Ui::Widget *ui;
};

#endif // WIDGET_H
