#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->toolButton,SIGNAL(clicked()),this,SLOT(chooseSource()) );

}

Widget::~Widget()
{
    delete ui;
}

void Widget::chooseSource(void)
{
    chooseImage(tr("Choose Source Image"), &srcImg, ui->toolButton);
}

void Widget::chooseImage(const QString &title, QImage *image, QToolButton *button)
{
    QString fileName = QFileDialog::getOpenFileName(this, title);

    if (!fileName.isEmpty())
    {
            loadImage(fileName, image, button);
    }
}

void Widget::loadImage(const QString &fileName, QImage *image, QToolButton *button)
{
    image->load(fileName);
    button->setIconSize(QSize(image->width(), image->height()));
    button->setIcon(QPixmap::fromImage(*image));
}
