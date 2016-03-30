#include "VideoStream.h"

VideoStream::VideoStream() {
	this->videoCapture = new cv::VideoCapture(0);
}

VideoStream::VideoStream(std::string fileUri) {
	//TODO implement
}

VideoStream::~VideoStream() {
	delete videoCapture;
}

cv::Mat* VideoStream::getFrame() {
	cv::Mat *image = new cv::Mat();
	cv::Mat *grayImage = new cv::Mat();

	videoCapture->read(*image);
	
	cv::cvtColor(*image, *grayImage, CV_BGR2GRAY);

	delete image;

	return grayImage;
}
