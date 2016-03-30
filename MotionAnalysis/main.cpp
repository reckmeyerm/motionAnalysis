#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

//#define THRESHOLD 20
//
//using namespace std;
//using namespace cv;
//
//int main(void) {
//	Mat image;
//	Mat grayImage;
//	Mat backgroundImage;
//	Mat *diffImage = NULL;
//
//	int rows = 0;
//	int cols = 0;
//
//	VideoCapture stream(0);
//
//	stream.read(image);
//	cvtColor(image, grayImage, CV_BGR2GRAY);
//	rows = grayImage.rows;
//	cols = grayImage.cols;
//
//	backgroundImage = grayImage.clone();
//	
//	while (true) {
//		stream.read(image);
//		cvtColor(image, grayImage, CV_BGR2GRAY);
//		
//		if (diffImage != NULL) {
//			delete diffImage;
//		}
//		diffImage = new Mat(rows, cols, CV_8U);
//
//		for (unsigned int i = 0; i < (unsigned int)(rows*cols); i++) {
//			int difference = abs(grayImage.data[i] - backgroundImage.data[i]);
//
//			if (difference > THRESHOLD) {
//				diffImage->data[i] = 255;
//			}
//			else {
//				diffImage->data[i] = 0;
//			}
//		}
//
//
//
//		imshow("diffImage", *diffImage);
//		//imshow("actImage", grayImage);
//		//imshow("bgImage", backgroundImage);
//		waitKey(1);
//
//		backgroundImage = grayImage.clone();
//	}
//
//
//
//	return 0;
//}

#include "VideoStream.h"
#include "DifferenceImage.h"
#include "HeatImage.h"

using namespace std;
using namespace cv;

int main(void) {
	VideoStream *videoStream = new VideoStream();
	DifferenceImage *differenceImage = new DifferenceImage();
	HeatImage *heatImage = new HeatImage();

	Mat *image = NULL;
	Mat *bgImage = NULL;
	Mat *diffImage = NULL;
	Mat *htImage = NULL;

	//namedWindow("actImage", CV_WINDOW_AUTOSIZE);
	//namedWindow("bgImage", CV_WINDOW_AUTOSIZE);
	namedWindow("diffImage", CV_WINDOW_AUTOSIZE);
	namedWindow("heatImage", CV_WINDOW_AUTOSIZE);

	bgImage = videoStream->getFrame();

	while (true) {
		image = videoStream->getFrame();

		differenceImage->generate(image, bgImage);
		diffImage = differenceImage->get();

		heatImage->generate(diffImage);
		htImage = heatImage->get();

		//imshow("actImage", *image);
		//imshow("bgImage", *image);
		imshow("diffImage", *diffImage);
		imshow("heatImage", *htImage);
		waitKey(1);

		heatImage->degenerate();

		delete bgImage;
		bgImage = image;
	}
	delete image;

	return 0;
}