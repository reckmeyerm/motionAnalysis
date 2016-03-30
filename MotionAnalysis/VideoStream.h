#pragma once

#ifndef VIDEO_STREAM_H_
#define VIDEO_STREAM_H_

#include <string>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp> 

class VideoStream {
private:
	cv::VideoCapture *videoCapture;
	std::string fileUri;
public:
	VideoStream();
	VideoStream(std::string fileUri);
	~VideoStream();

	cv::Mat* getFrame();
};

#endif