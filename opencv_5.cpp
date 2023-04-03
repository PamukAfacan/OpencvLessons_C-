#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

//Canny kenarlar� bulmay� sa�lar.
//Gray rengi gri y�zeye ta��maya sa�lar.
//Blur ad� �st�nde blurlamaya yarar.

using namespace cv;
using namespace std;



void main() {

	//Blank Image

	Mat img(512, 512, CV_8UC3, Scalar(255, 255, 255));

	circle(img, Point(256, 256), 155, Scalar(0, 69, 255),FILLED);
	rectangle(img, Point(130, 226), Point(382, 286), Scalar(255, 255, 255), FILLED);
	line(img, Point(130, 296), Point(382, 296), 2);

	putText(img, "Pamuksama", Point(137, 262), FONT_HERSHEY_DUPLEX, 0.7, Scalar(0, 69, 255), 2);






	imshow("Image1", img);
	



	waitKey(0);

}