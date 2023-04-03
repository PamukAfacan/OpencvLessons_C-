#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>

#include <iostream>


using namespace cv;
using namespace std;

float w = 250, h = 350;
float w1 = 250, h1 = 350;
Mat matrix,matrix1, imgWarp,imgWarp1;

void main() {


	string path = ("Resources/cards.jpg");
	Mat img = imread(path);

	Point2f src[4] = { {529,142},{771,190},{405,395},{674,457}};
	Point2f dst[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h}};

	Point2f src1[4] = { {66,323},{334,279},{91,635},{402,570} };
	Point2f dst1[4] = { {0.0f,0.0f},{w,0.0f},{0.0f,h},{w,h} };

	matrix = getPerspectiveTransform(src, dst);
	warpPerspective(img, imgWarp, matrix, Point(w, h));

	matrix1 = getPerspectiveTransform(src1, dst1);
	warpPerspective(img, imgWarp1, matrix1, Point(w, h));

	for (int i = 0; i < 4; i++) {
		circle(img, src[i], 10, Scalar(0, 0, 255), FILLED);
	}

	for (int i = 0; i < 4; i++) {
		circle(img, src1[i], 10, Scalar(0, 0, 255), FILLED);
	}

	imshow("Image", img);
	imshow("Image Warp", imgWarp);
	imshow("Image Warp1", imgWarp1);

	waitKey(0);

	   

}