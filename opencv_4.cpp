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

	string path = ("Resources/1.jpg");
	Mat img = imread(path);
	Mat imgResize,imgCrop;

	//cout << img.size() << endl;
	resize(img,imgResize,Size(),0.5,0.5);

	//for the crop
	Rect roi(100, 100, 300, 250);
	imgCrop = img(roi);


	imshow("Image1", img);
	imshow("Image2", imgResize);
	imshow("Image3", imgCrop);
	


	waitKey(0);

}