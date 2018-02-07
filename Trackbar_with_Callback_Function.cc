// There are two variable will be pass to the callback function. We will fixed one base on their 
// passed in plot condition. And change the other to make difference of the plot.
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat src;

// The function have two variables in it one is for Brightness, the other is for Contrast
// Because we are not sure about the second parameter, so just pass in the data with void type 
// and do the static_cast to change the type
void MyCallbackForBrightness(int iValueForBrightness,void *userData)
{
    Mat dst;
    int iValueForContrast = *( static_cast<int*>(userData));
    
    int iBrightness = iValueForBrightness-50;
    double dContrast = iValueForContrast / 50.0;

    cout << "MyCallbackForBrightness : Contrast=" << dContrast <<",Brightness=" << iBrightness << endl;

    src.convertTo(dst,-1,dContrast,iBrightness);

    imshow("My window",dst);

}

// The function have two variables in it one is for Brightness, the other is for Contrast
void MyCallbackForContrast(int iValueForContrast,void *userData)
{
    Mat dst;
    int iValueForBrightness = *(static_cast<int*>(userData));

    int iBrightness = iValueForBrightness-50;
    double dContrast = iValueForContrast/50.0;

    cout << "MyCallbackForContrast : Contrast=" << dContrast <<",Brightness=" << iBrightness << endl;
    src.convertTo(dst,-1,dContrast,iBrightness);

    imshow("My Window",dst);

}

int main(int argc,char**argv)
{
    src = imread("/Users/Apple/Desktop/Not_Female_result.jpg");

    if(src.data == false)
    {
        cout << "Error loading the image" << endl;
        return -1;

    }

    namedWindow("My Window",1);

    int iValueForBrightness = 50;
    int iValueForContrast = 50;

    createTrackbar("Brightness","My Window",&iValueForBrightness,100,MyCallbackForBrightness,&iValueForContrast);
    createTrackbar("Contrast","My Window",&iValueForContrast,100,MyCallbackForContrast,&iValueForBrightness);

    imshow("My Window",src);

    waitKey(0);

    return 0;
}

