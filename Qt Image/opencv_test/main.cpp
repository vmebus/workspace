#include <QCoreApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    cv::Mat image = cv::imread("D:\\workspace\\pictures\\i23876-12.jpg");
    cv::namedWindow("My Image");
    cv::imshow("My Image", image);
    cv::waitKey(5000);

    return a.exec();
}
