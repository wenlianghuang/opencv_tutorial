//#include "stdafx.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/opencv.hpp"
using namespace std;
using namespace cv;

int main(int argc,char **argv)
{

    Mat image = imread("/Users/Apple/Desktop/Not_Female_result.jpg");

    if(image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }

    string windowName = "MyWindow";

    namedWindow(windowName,WINDOW_AUTOSIZE);

    imshow(windowName,image);

    bitwise_not(image,image);
    namedWindow("Inverted");
    imshow("Inverted",image);

    waitKey(0);

    destroyAllWindows();

    return 0;
}
