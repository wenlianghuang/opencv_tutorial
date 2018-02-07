#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int main(int argc, char**argv)
{
    Mat imgOriginal = imread("/Users/Apple/Desktop/Not_Female_result.jpg");

    const char* pzOriginalImage = "Original Image";
    namedWindow(pzOriginalImage,CV_WINDOW_AUTOSIZE);
    imshow(pzOriginalImage,CV_WINDOW_AUTOSIZE);

    const char* pzRotatedImage = "Rotated Image";
    namedWindow(pzRotatedImage,CV_WINDOW_AUTOSIZE);

    int iAngle = 180;
    createTrackbar("Angle",pzRotatedImage,&iAngle,360); // iAngle is the initial value where the trackbar will locate, and 360 is the maximum value. 

    int iImageHeight = imgOriginal.rows/3;
    int iImageWidth = imgOriginal.cols/3;

    while(true)
    {
        Mat matRotation = getRotationMatrix2D( Point(iImageWidth,iImageHeight),(iAngle),1); //Point tuple represent the rotational pivot of the plot 

        Mat imgRotated;
        warpAffine(imgOriginal,imgRotated,matRotation,imgOriginal.size());
        imshow(pzRotatedImage,imgRotated);

        int iRet = waitKey(30);
        if(iRet == 27)
        {
            break;
        }
    }

    return 0;
}
