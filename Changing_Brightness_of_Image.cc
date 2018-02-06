#include<opencv2/opencv.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char **argv)
{
    Mat image = imread("/Users/Apple/Desktop/Not_Female_result.jpg");

    if(image.empty() == true)
    {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }

    Mat imageBrightnessHight50;
    image.convertTo(imageBrightnessHight50,-1,2,50); //Origin number*1+50 the third one is multiply and the fourth is add

    Mat imageBrightnessHight100;
    image.convertTo(imageBrightnessHight100,-1,2,100);

    Mat imageBrightnessLow50;
    image.convertTo(imageBrightnessLow50,-1,1,-50);

    Mat imageBrightnessLow100;
    image.convertTo(imageBrightnessLow100,-1,1,-100);

    string windowNameOriginalImage = "Original Image";
    string windowNameBrightnessHigh50 = "Brightness Increased by 50";
    string windowNameBrightnessHigh100 = "Brightness Increased by 100";
    string windowNameBrightnessLow50 = "Brightness Decreased by 50";
    string windowNameBrightnessLow100 = "Brightness Decreased by 100";

    namedWindow(windowNameOriginalImage,WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh50,WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh100,WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow50,WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow100,WINDOW_NORMAL);

    imshow(windowNameOriginalImage,image);
    imshow(windowNameBrightnessHigh50,imageBrightnessHight50);
    imshow(windowNameBrightnessHigh100,imageBrightnessHight100);
    imshow(windowNameBrightnessLow50,imageBrightnessLow50);
    imshow(windowNameBrightnessLow100,imageBrightnessLow100);

    waitKey(0);

    destroyAllWindows();

    return 0;
}

