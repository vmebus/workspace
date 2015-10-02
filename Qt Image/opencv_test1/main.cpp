#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cout<<"000000000"<<endl;
    Mat img = imread("D:\\i23876-12.jpg", CV_LOAD_IMAGE_COLOR);
    int w = img.cols;
    int h = img.rows;
    Size s = Size(w, h);

    Mat grayImg = Mat(s, CV_8UC1);
    cvtColor(img, grayImg, COLOR_RGB2GRAY);

    namedWindow("Image", CV_WINDOW_AUTOSIZE);
    imshow("Image", img);

    namedWindow("Gray", CV_WINDOW_AUTOSIZE);
    imshow("Gray", grayImg);

    waitKey(0);

    cout<<"11111111"<<endl;

    return a.exec();
}
