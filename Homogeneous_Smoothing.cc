// The most important thing about bluring is "kernel", which represent the type of filter to filt
// the plot

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;

int main(int argc,char **argv)
{
    namedWindow("Origin Image",CV_WINDOW_AUTOSIZE);
    namedWindow("Smoothed Image",CV_WINDOW_AUTOSIZE);

    Mat src = imread("/Users/Apple/Desktop/Not_Female_result.jpg");

    imshow("Origin Image",src);

    Mat dst;

    char zBuffer[35];

    for(int i = 1;i<31;i+=2)
    {
        snprintf(zBuffer,35,"Kernel Size: %d x %d",i,i);

        blur(src,dst,Size(i,i));

        imshow("Smoothed image",dst);

        int c = waitKey(2000);

        if( c == 27)
        {
            return 0;
        }
    }

    dst = Mat::zeros(src.size(),src.type());
    snprintf(zBuffer,35,"Press Any Key to Exit");

    putText(dst,zBuffer,Point(src.cols/4,src.rows/2),CV_FONT_HERSHEY_COMPLEX,1,Scalar(255,255,255));
    imshow("Smooted Image",dst);

    waitKey(0);

    return 0;
}


