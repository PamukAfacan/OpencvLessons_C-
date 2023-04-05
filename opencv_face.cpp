#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>


using namespace cv;

using namespace std;

void main() {


	string path = ("Resources/face.jpg");
	Mat img = imread(path);
	Mat imgResize;

	//CascadeClassifier faceCascade;
	//faceCascade.load
	resize(img, imgResize, Size(), 0.1, 0.1);

	CascadeClassifier faceCascade;
	faceCascade.load("Resources/haarcascade_frontalface_default.xml");

	if (faceCascade.empty()) { cout << "XML file not found" << endl; }

	vector<Rect>faces;
	faceCascade.detectMultiScale(imgResize, faces, 1.1, 10);

	for (int i = 0; i < faces.size(); i++) {
		rectangle(imgResize, faces[i].tl(),faces[i].br(),Scalar(255, 255, 255), 3);
	}

	imshow("Image", imgResize);
	waitKey(0);

}