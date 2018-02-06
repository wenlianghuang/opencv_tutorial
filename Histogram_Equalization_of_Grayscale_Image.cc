#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
    Mat img = imread("/Users/Apple/Desktop/Not_Female_result.jpg",CV_LOAD_IMAGE_COLOR);

    if(img.empty())
    {
        cout << "Image cannot be loaded...!!" << endl;
        return -1;
    }
    Mat outimg;
    cvtColor(img,outimg,CV_BGR2GRAY);

    Mat img_hist_equalized;
    equalizeHist(outimg,img_hist_equalized);

    namedWindow("Original Image",CV_WINDOW_AUTOSIZE);
    namedWindow("Histogram Equalized",CV_WINDOW_AUTOSIZE);

    imshow("Original Image",outimg);
    imshow("Histogram Equalized",img_hist_equalized);

    waitKey(0);

    destroyAllWindows();

    return 0;
}

