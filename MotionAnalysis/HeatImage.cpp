#include "HeatImage.h"

HeatImage::HeatImage() {
	heatImage = NULL;
}

void HeatImage::generate(cv::Mat *image) {
	unsigned int rows = image->rows;
	unsigned int cols = image->cols;
	unsigned int size = rows * cols;

	if (heatImage == NULL) {
		heatImage = new cv::Mat(rows, cols, CV_8UC3);
		for (unsigned int i = 0; i < size * 3; i++) {
			heatImage->data[i] = 0;
		}
	}

	for (unsigned int i = 0; i < size; i++) {
		int position = i * 3;

		if (image->data[i] == 255) {
			if (heatImage->data[position] < 255) {
				if (heatImage->data[position] + (1 * ACCELERATION_RATE) > 255) {
					heatImage->data[position] = 255;
				}
				else {
					heatImage->data[position] += (1 * ACCELERATION_RATE);
				}
			}

			else if (heatImage->data[position+1] < 255) {
				if (heatImage->data[position+1] + (1 * ACCELERATION_RATE) > 255) {
					heatImage->data[position+1] = 255;
				}
				else {
					heatImage->data[position + 1] += (1 * ACCELERATION_RATE);
				}
			}

			else if (heatImage->data[position+2] < 255) {
				if (heatImage->data[position+2] + (1 * ACCELERATION_RATE) > 255) {
					heatImage->data[position+2] = 255;
				}
				else {
					heatImage->data[position + 2] += (1 * ACCELERATION_RATE);
				}
			}
		}
	}
}

void HeatImage::degenerate() {
	unsigned int rows = heatImage->rows;
	unsigned int cols = heatImage->cols;
	unsigned int size = rows * cols;

	if (heatImage != NULL) {
		for (unsigned int i = 0; i < size; i++) {
			int position = i * 3;

			if (heatImage->data[position + 2] > 0) {
				if (heatImage->data[position + 2] - (1 * DECELERATION_RATE) < 0) {
					heatImage->data[position + 2] = 0;
				}
				else {
					heatImage->data[position + 2] -= (1 * DECELERATION_RATE);
				}
			}
			else if (heatImage->data[position + 1] > 0) {
				if (heatImage->data[position + 1] - (1 * DECELERATION_RATE) < 0) {
					heatImage->data[position + 1] = 0;
				}
				else {
					heatImage->data[position + 1] -= (1 * DECELERATION_RATE);
				}
			}
			else {
				if (heatImage->data[position] - (1 * DECELERATION_RATE) < 0) {
					heatImage->data[position] = 0;
				}
				else {
					heatImage->data[position] -= (1 * DECELERATION_RATE);
				}
			}
		}
	}
}

cv::Mat* HeatImage::get() {
	return heatImage;
}