#pragma once

#ifndef DIFFERENCE_IMAGE_H_
#define DIFFERENCE_IMAGE_H_

#define THRESHOLD 20

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 

class DifferenceImage {
private:
	cv::Mat *diffImage;
public:
	DifferenceImage();

	void generate(cv::Mat *actImage, cv::Mat *bgImage);
	cv::Mat* get();
};

#endif