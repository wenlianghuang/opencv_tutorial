#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc,char **argv)
{

    Mat src = imread("/Users/Apple/Desktop/Not_Female_result.jpg");

    if(!src.data)
    {
        cout << "Error loading the image" << endl;
        return -1;
    }

    namedWindow("My Window", 1); // The name "My Window" follows the name of window all the time until the program end, every function want to call this function use this name."
    
    // Create trackbar to change brightness
    int iSliderValue1 = 50;
    createTrackbar("Brightness","My Window",&iSliderValue1,100);

    //Create trackbar to change contrast
    int iSliderValue2 = 50;
    createTrackbar("Contrast","My Window", &iSliderValue2,100);
    
    while(true)
    {
        Mat dst;
        int iBrightness = iSliderValue1-50;
        double dContrast = iSliderValue2/50.0;
        src.convertTo(dst,-1,iBrightness,dContrast);
        
        imshow("MyWindow",dst);

        if(waitKey(50) == 27)
        {
            break;
        }
    }

    return 0;
}
