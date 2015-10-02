#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

void salt(Mat &image, int n);
void colorReduce(Mat &image, int div);
void sharpen(const Mat &image, Mat &result);
void sharpen2D(const Mat &image, Mat &result);

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mat image = imread("D:\\workspace\\pictures\\boldt_castle.jpg");
    Mat logo = imread("D:\\workspace\\pictures\\qisda.jpg");

    Mat imageROI = image(Rect(531,444,logo.cols,logo.rows));
    logo.copyTo(imageROI,logo);
    //printf("%d  %d",image.cols, image.rows);
    //Mat imageclone = image.clone();
    //salt(image,3000);
    //colorReduce(imageclone, 64);
    //Mat gray = imread("D:\\rain.jpg");
    //cvtColor(image, gray, CV_BGR2GRAY);
    //sharpen2D(image, gray);
    //addWeighted(imageROI,1.0,logo,0.3,0.,imageROI);

    //namedWindow("My Image");
    //imshow("My Image", image);
    namedWindow("Changed Image");
    imshow("Changed Image", image);


    waitKey(50000);

    return a.exec();
}



void salt(Mat &image, int n)
{
    for(int k=0;k<n;k++)
    {
        int i = rand()%image.cols;
        int j = rand()%image.rows;

        if(image.channels() == 1)
        {
            image.at<uchar>(j,i) = 255;
        }
        else if(image.channels() == 3)
        {
            image.at<Vec3b>(j,i)[0] = 255;
            image.at<Vec3b>(j,i)[1] = 255;
            image.at<Vec3b>(j,i)[3] = 255;
        }
    }
}

void colorReduce(Mat &image, int div)
{
    int nl = image.rows;
    int nc = image.cols*image.channels();

    for(int j=0; j<nl; j++)
    {
        uchar* data = image.ptr<uchar>(j);

        for (int i=0; i<nc; i++)
        {
            data[i]=data[i]/div*div+div/2;
        }
    }
}

void sharpen(const Mat &image, Mat &result)
{
    result.create(image.size(), image.type());

    for (int j=1; j< image.rows-1; j++)
    {
        const uchar* previous = image.ptr<const uchar>(j-1);
        const uchar* current = image.ptr<const uchar>(j);
        const uchar* next = image.ptr<const uchar>(j+1);
        uchar* output = result.ptr<uchar>(j);

        for (int i=1; i< image.cols-1; i++)
        {
            *output++= saturate_cast<uchar>(5*current[i]-current[i-1]
                                             -current[i+1]-previous[i]-next[i]);
        }
    }

    result.row(0).setTo(Scalar(0));
    result.row(result.rows-1).setTo(Scalar(0));
    result.col(0).setTo(Scalar(0));
    result.col(result.cols-1).setTo(Scalar(0));
}


void sharpen2D(const Mat &image, Mat &result)
{
    Mat kernel(3,3,CV_32F,Scalar(0));
    kernel.at<float>(1,1) = 5.0;
    kernel.at<float>(0,1) = -1.0;
    kernel.at<float>(2,1) = -1.0;
    kernel.at<float>(1,0) = -1.0;
    kernel.at<float>(1,2) = -1.0;
    filter2D(image,result,image.depth(),kernel);
}




