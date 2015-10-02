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

private slots:
    void chooseSource(void);
    void doNearest(void);
    void doBilinear(void);
    void setScale(void);

private:
    QImage srcImg;
    QImage nrstImg;
    QImage biImg;

    int scale;

    Ui::Widget *ui;
};

#endif // WIDGET_H

