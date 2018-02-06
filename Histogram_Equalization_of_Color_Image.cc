#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, const char **argv)
{
    Mat img = imread("/Users/Apple/Desktop/Not_Female_result.jpg",CV_LOAD_IMAGE_COLOR);

    if(img.empty())
    {
        cout << "Image cannot be loaded...!!" << endl;
        return -1;
    }

    vector<Mat> channels;
    Mat img_hist_equalized;

    cvtColor(img,img_hist_equalized,CV_BGR2YCrCb); // Because we only want to change the intensity of the plot, so we need to change to the space which contains intensity "YCrCb"
    split(img_hist_equalized,channels);
    equalizeHist(channels[0],channels[0]);//channle[0] is the "Y" in "YCrCb" which represent the intensity
    merge(channels,img_hist_equalized); //merge 3 channels including the modified 1st channel into one image
    cvtColor(img_hist_equalized,img_hist_equalized,CV_YCrCb2BGR);

    namedWindow("Original Image",CV_WINDOW_AUTOSIZE);
    namedWindow("Histogram Equalized",CV_WINDOW_AUTOSIZE);

    imshow("Original image",img);
    imshow("Histogram Equalized",img_hist_equalized);

    waitKey(0);

    destroyAllWindows();

    return 0 ;
}
    
