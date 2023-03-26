// opencv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>


using namespace cv;

using namespace std;

void main() {

	
	string path = ("C:/Users/cefat/OneDrive/Masaüstü/1.jpg");
	Mat img1 = imread(path);

	imshow("Image",img1);
	waitKey(0);
	
	

	string path = ("C:/Users/cefat/OneDrive/Masaüstü/2.mp4");
	VideoCapture cap(path);
	Mat img2;

	while (true) {

		    cap.read(img2);
			imshow("Image", img2);
			waitKey(50);





	}


	

	
	
	Mat image;

	namedWindow("Display window");

	VideoCapture cap(0);

	if (!cap.isOpened()) {

		cout << "cannot open camera";

	}

	while (true) {

		cap >> image;

		imshow("Display window", image);

		waitKey(25);

	}
	return 0;
	
	
	

}
