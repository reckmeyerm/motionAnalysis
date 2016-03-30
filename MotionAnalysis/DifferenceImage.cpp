#include "DifferenceImage.h"

#include <iostream>

DifferenceImage::DifferenceImage() {
	this->diffImage = NULL;
}

void DifferenceImage::generate(cv::Mat *actImage, cv::Mat *bgImage) {
	if (diffImage != NULL) {
		delete diffImage;
	}

	unsigned int rows = actImage->rows;
	unsigned int cols = actImage->cols;
	unsigned int size = rows * cols;

	diffImage = new cv::Mat(rows, cols, CV_8U);

	for (unsigned int i = 0; i < size; i++) {
		//std::cout << "pixel no. " << i << " out of " << size << std::endl;

		unsigned int difference = abs(actImage->data[i] - bgImage->data[i]);

		if (difference > THRESHOLD) {
			diffImage->data[i] = 255;
		}
		else {
			diffImage->data[i] = 0;
		}

	}

	// filtering
	cv::erode(*diffImage, *diffImage, cv::Mat(), cv::Point(-1, -1), 1, 0);
	cv::dilate(*diffImage, *diffImage, cv::Mat(), cv::Point(-1, -1), 1, 0);
	cv::medianBlur(*diffImage, *diffImage, 3);
}

cv::Mat* DifferenceImage::get() {
	return diffImage;
}