#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QImage>


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
    void Sobel(void);
    void LoG(void);

private:
    Ui::Widget *ui;
    QImage srcImg;
    QImage rsltImg;
};

#endif // WIDGET_H
