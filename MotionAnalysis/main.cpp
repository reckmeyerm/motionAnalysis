#define DEBUG false

#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

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

	if (DEBUG == true) {
		namedWindow("actImage", CV_WINDOW_AUTOSIZE);
		namedWindow("bgImage", CV_WINDOW_AUTOSIZE);
	}

	namedWindow("diffImage", CV_WINDOW_AUTOSIZE);
	namedWindow("heatImage", CV_WINDOW_AUTOSIZE);

	bgImage = videoStream->getFrame();

	while (true) {
		image = videoStream->getFrame();

		differenceImage->generate(image, bgImage);
		diffImage = differenceImage->get();

		heatImage->generate(diffImage);
		htImage = heatImage->get();

		if (DEBUG == true) {
			imshow("actImage", *image);
			imshow("bgImage", *image);
		}

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