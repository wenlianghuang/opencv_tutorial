#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;
using namespace cv;

int main(int argc,char** argv)
{
    VideoCapture cap("/Users/Apple/Desktop/諸葛亮去世後劉禪為什麽要禁止百姓官員去奔喪.mp4");

    if(cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get();
        return -1;
    }

    
    double fps = cap.get(CAP_PROP_FPS);
    cout << "Frame per seconds : " << fps << endl;

    string window_name = "My First Video";
    namedWindow(window_name,WINDOW_NORMAL);

    while(true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame);
        
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        imshow(window_name,frame);

        if(waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stopping the video" << endl;
            break;
        }
    }

    return 0;
}


