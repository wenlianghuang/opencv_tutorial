//It seems relateively path name is not recognizable
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    Mat image = imread("/Users/Apple/Desktop/Not_Female_result.jpg"); 

    if(image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get();
        return -1;
    }

    bool isSuccess = imwrite("/Users/Apple/Desktop/MyImage.jpg",image);

    if(isSuccess == false)
    {
        cout << "Faild to save the image" << endl;
        cin.get();
        return -1;
    }

    cout << "Image is successfully save to a file" << endl;

    string windowName = "The Saved Image";
    namedWindow(windowName);
    imshow(windowName,image);

    waitKey(0);

    destroyWindow(windowName);

    return 0;
}

