#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::displayResult(cv::Mat mat)
{   //show the resultImage in result area;
    cv::Mat rgb;
    QImage img;

    if(mat.channels() == 3)    // RGB image
    {
        cvtColor(mat,rgb,CV_BGR2RGB);
        img = QImage((const uchar*)(rgb.data),  //(const unsigned char*)
                     rgb.cols,rgb.rows,
                     rgb.cols*rgb.channels(),   //new add
                     QImage::Format_RGB888);
    }else                     // gray image
    {
        img = QImage((const uchar*)(mat.data),
                     mat.cols,mat.rows,
                     mat.cols*mat.channels(),    //new add
                     QImage::Format_Indexed8);
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
    ui->label->resize(ui->label->pixmap()->size());
    ui->label->show();
}

void MainWindow::on_pushButton_clicked()
{
     QString fileName = QFileDialog::getOpenFileName(this,
                tr("Open Image"),".",
                tr("Image File (*.png *.jpg *.jpeg *.bmp)"));
     image = cv::imread(fileName.toLatin1().data(),CV_LOAD_IMAGE_COLOR);

     if (image.data){
         ui->pushButton_2->setEnabled(true);
     }

     displayResult(image);

     cv::namedWindow("Original Image");
     cv::imshow("Original Image", image);
}

void MainWindow::on_pushButton_2_clicked()
{
    cv::flip(image, image, 1);

    displayResult(image);

    cv::namedWindow("Output Image");
    cv::imshow("Output Image", image);
}


