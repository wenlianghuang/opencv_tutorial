#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{
    Mat image(600,800,CV_8UC3,Scalar(100,250,30));

    string windowName = "Window with Blank Image.";

    namedWindow(windowName);

    imshow(windowName,image);

    waitKey(0);

    destroyWindow(windowName);

    return 0;
}
