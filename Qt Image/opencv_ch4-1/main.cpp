#include <QCoreApplication>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>

using namespace std;
using namespace cv;

class Histogram1D
{
private:
    int histSize[1];
    float hranges[2];
    const float* ranges[1];
    int channels[1];
public:
    Histogram1D()
    {
        histSize[0] = 256;
        hranges[0] = 0.0;
        hranges[1] = 255.0;
        ranges[0] = hranges;
        channels[0] = 0;
    }

    MatND getHistogram(const Mat &image)
    {
        MatND hist;
        calcHist(&image,
                1,
                channels,
                Mat(),
                hist,
                1,
                histSize,
                ranges);
        return hist;
    }

    Mat getHistogramImage(const Mat &image)
    {
        MatND hist = getHistogram(image);

        double maxVal = 0;
        double minVal = 0;

        minMaxLoc(hist,&minVal,&maxVal,0,0);
        Mat histImg(histSize[0],histSize[0],CV_8U,Scalar(255));
        int hpt = static_cast<int>(0.9*histSize[0]);

        for (int h=0; h<histSize[0];h++)
        {
            float binVal = hist.at<float>(h);
            int intensivity = static_cast<int>(binVal*hpt/maxVal);

            line(histImg, Point(h,histSize[0]),
                 Point(h,histSize[0]-intensivity),
                 Scalar::all(0));
        }
        return histImg;
    }

    Mat applyLookUp(const Mat &image, const Mat &lookup)
    {
        Mat result;
        LUT(image,lookup,result);
        return result;
    }
    Mat stretch(const Mat &image, int minValue=0)
    {
        MatND hist = getHistogram(image);
        int imin =0;
        for(;imin<histSize[0];imin++)
        {
            cout << hist.at<float>(imin) << endl;
            if (hist.at<float>(imin)>minValue)
                break;
        }
        int imax = histSize[0]-1;
        for(;imax>=0;imax--)
        {
            if (hist.at<float>(imax)>minValue)
                            break;
        }
        int dim(256);
        Mat lookup( 1,
                    &dim,
                    CV_8U);
        for(int i=0;i<256;i++)
        {
            if (i<imin)
                lookup.at<uchar>(i)=0;
            else if (i>imax)
                lookup.at<uchar>(i)=255;
            else
                lookup.at<uchar>(i)= static_cast<uchar>(255.0*(i-imin)/(imax-imin)+0.5);
        }
        Mat result;
        result = applyLookUp(image,lookup);
        return result;
    }
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Mat image = imread("D:\\workspace\\pictures\\771413900_m.jpg",0);
    Mat thresholded, result;

    Histogram1D h;

    MatND histo = h.getHistogram(image);

    for (int i=0;i<256;i++)
        cout << "Value" << i << "=" << histo.at<float>(i) << endl;

    imshow("Orginal", image);

    imshow("Histogram",h.getHistogramImage(image));

    //threshold(image, thresholded,128,255,THRESH_BINARY);

    //imshow("Threshold",thresholded);

    equalizeHist(image,result);

    //Mat stretched = h.stretch(image,100);

    //imshow("Stretched",stretched);

    imshow("Equalize",result);

    imshow("After Equalize Histogram",h.getHistogramImage(result));


    waitKey(50000);

    return a.exec();
}






