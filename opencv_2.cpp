#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <iostream>

//Canny kenarlarý bulmayý saðlar.
//Gray rengi gri yüzeye taþýmaya saðlar.
//Blur adý üstünde blurlamaya yarar.

using namespace cv;
using namespace std;



void main() {

	string path = ("C:/Users/cefat/OneDrive/Masaüstü/1.jpg");
	Mat img = imread(path);
	Mat imgGray,imgBlur,imgCanny,imgDilate,imgErode;

	cvtColor(img,imgGray,COLOR_BGR2GRAY);
	GaussianBlur(img, imgBlur, Size(7, 7), 5, 0);
	Canny(imgBlur, imgCanny, 50, 150);

	Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));


	dilate(imgCanny, imgDilate, kernel);
	erode(imgDilate, imgErode, kernel);


	imshow("Image", img);
	imshow("Image Gray", imgGray);
	imshow("Image Blur", imgBlur);
	imshow("Image Canny", imgCanny);
	imshow("Image Dilate", imgDilate);
	imshow("Image Erode", imgErode);


	waitKey(0);
	
}