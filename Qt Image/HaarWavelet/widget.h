#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QImage>
#include <QToolButton>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void dowavelet(int w, int h);

private slots:
    void chooseSource(void);
    void Wavelet(void);

private:
    Ui::Widget *ui;
    QImage srcImg;
    QImage rsltImg;

};

#endif // WIDGET_H
