#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

using namespace std;
using namespace cv;

int main()
{
    Mat src = imread("/Users/Apple/Desktop/DetectingContours.jpg");
    printf("Total pixel number %lu",src.total());
    Mat imgGrayScale;
    cvtColor(src,imgGrayScale,CV_BGR2GRAY);

    namedWindow("GrayScale Image");
    imshow("GrayScale Image",imgGrayScale);

    threshold(imgGrayScale,imgGrayScale,100,255,THRESH_BINARY_INV);

    namedWindow("Threshold Image");
    imshow("Threshold Image",imgGrayScale);

    vector <vector<Point> > contours;
    vector <Vec4i> hierarchy;
    vector<vector<Point> > results;

    findContours(imgGrayScale,contours,hierarchy,CV_RETR_LIST,CHAIN_APPROX_SIMPLE);
    results.resize(contours.size());
    
    for(int k = 0;k<contours.size();k++)
    {
        double length = arcLength(contours[k],1)*0.02;

        approxPolyDP(contours[k],results[k],length,1);
        cout << results[k].size() << endl; 
        if(results[k].size() == 3 && contourArea(results[k]) > 100)
        {
            CvPoint pt[3];
            for (int i = 0;i<3;i++)
            {
                pt[i] = results[k][i];
            }

            line(src,pt[0],pt[1],cvScalar(255,0,0),4);
            line(src,pt[1],pt[2],cvScalar(255,0,0),4);
            line(src,pt[2],pt[0],cvScalar(255,0,0),4);

        }

        if(results[k].size() == 4 && (contourArea(results[k])<100000)){
            CvPoint pt[4];
            for(int i = 0;i<4;i++)
            {
                pt[i] = results[k][i];
            }

            line(src,pt[0],pt[1],cvScalar(0,255,0),4);
            line(src,pt[1],pt[2],cvScalar(0,255,0),4);
            line(src,pt[2],pt[3],cvScalar(0,255,0),4);
            line(src,pt[3],pt[0],cvScalar(0,255,0),4);

        }




        
    }
    namedWindow("Tracked");
    imshow("Tracked",src);
        
    waitKey(0);

    destroyAllWindows();

    return 0;
}

