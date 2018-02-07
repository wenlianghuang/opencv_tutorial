#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace cv;
int main()
{
         Mat src = imread("/Users/Apple/Desktop/FindingContours.png");
         
         Mat imgGrayScale(src.rows,src.cols,CV_8UC1);
         cvtColor(src,imgGrayScale,CV_BGR2GRAY);
         
         threshold(imgGrayScale,imgGrayScale,128,255,THRESH_BINARY);//From pixel 128~255, the interesting part is forward, not interesting part is bakcground.

         
         vector< vector<Point> > contours;
         vector<Vec4i> hierarchy;
         vector< vector<Point> > results;//A 2D vector, one dimension is for the index of shape, the other is for tht number of vertex.
         findContours(imgGrayScale,contours,hierarchy,CV_RETR_CCOMP,CHAIN_APPROX_SIMPLE);
         results.resize(contours.size());
         Rect r;
         
         for(int k = 0;k < contours.size();k++){
             double a = arcLength(contours[k],1);
             double length = a;
             // If I do not multiple 0.02, then the vertex number won't be right because the 
             // approxPolyDP will consider it as a vertex if the perimeter is too large.
             approxPolyDP(contours[k],results[k],length*0.05,1);
            if(results[k].size() == 3) // grab the vertex number
            {
                CvPoint pt[3];
                for(int i =0;i<3;i++)
                {
                    pt[i] = results[k][i];
                }

                line(src,pt[0],pt[1],CvScalar(255,0,0),4); // Draw the line between two points
                line(src,pt[1],pt[2],CvScalar(255,0,0),4);
                line(src,pt[2],pt[0],CvScalar(255,0,0),4);
            }

            else if (results[k].size() == 4)
            {
                CvPoint pt[4];
                for (int i =0;i<4;i++)
                {
                    pt[i] = results[k][i];
                }

                line(src,(pt[0]),(pt[1]),CvScalar(0,255,0),4);
                line(src,(pt[1]),(pt[2]),CvScalar(0,255,0),4);
                line(src,(pt[2]),(pt[3]),CvScalar(0,255,0),4);
                line(src,(pt[3]),(pt[0]),CvScalar(0,255,0),4);
                r = boundingRect(results[k]);
                break;
            }



         }
         namedWindow("Tracked");
         imshow("Tracked",src(r));
         waitKey(0);
          
         return 0;
}
