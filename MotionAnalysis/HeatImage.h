#pragma once

#ifndef HEAT_IMAGE_H_
#define HEAT_IMAGE_H_

#define ACCELERATION_RATE 50
#define DECELERATION_RATE 5

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 

class HeatImage {
private:
	cv::Mat *heatImage;
public:
	HeatImage();

	void generate(cv::Mat *image);
	void degenerate();
	cv::Mat* get();
};

#endif