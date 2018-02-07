#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

int iAngle = 180;
int iScale = 50;
int iBroderMode = 0;
Mat imgOriginal;
int iImageCenterX = 0;
int iImageCenterY = 0;

const char *pzRotationImage = "Rotated Image";

void CallbackForTrackBar(int, void*)
{
    Mat matRotation = getRotationMatrix2D(Point(iImageCenterX,iImageCenterY),(iAngle-180),(iScale/50.0));

    Mat imgRotated;
    warpAffine(imgOriginal,imgRotated,matRotation,imgOriginal.size(),INTER_LINEAR,iBroderMode,Scalar());
    imshow(pzRotationImage,imgRotated);
}

int main(int argc,char **argv)
{
    imgOriginal = imread("/Users/Apple/Desktop/Not_Female_result.jpg");
    
    iImageCenterX = imgOriginal.rows/2;
    iImageCenterY = imgOriginal.cols/2;

    const char* pzOriginalImage = "Original Image";
    namedWindow(pzOriginalImage,CV_WINDOW_AUTOSIZE);
    imshow(pzOriginalImage,imgOriginal);

    namedWindow(pzRotationImage,CV_WINDOW_AUTOSIZE);
    createTrackbar("Angle",pzRotationImage,&iAngle,360,CallbackForTrackBar);
    createTrackbar("Scale",pzRotationImage,&iScale,100,CallbackForTrackBar);
    createTrackbar("Border Mode",pzRotationImage,&iBroderMode,5,CallbackForTrackBar);

    int iDummy = 0;
    CallbackForTrackBar(iDummy,&iDummy); // This function do not change anything, it just want to satisfy the two parameters that need to be passed into the function.
    
    waitKey(0);

    return 0;
}

