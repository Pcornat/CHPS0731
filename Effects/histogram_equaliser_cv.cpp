//
// Created by Florent on 22/12/2018.
//

#include "histogram_equaliser_cv.h"
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <stdexcept>

bool HistogramEqualiserCV::effect(const std::vector<void*>& args) {
	if (args.size() != 1) {
		throw std::invalid_argument("Too much argument, only one is asked.\n");
	}
	double min, max, alpha, beta;
	cv::Mat hsv;
	auto& picture = *reinterpret_cast<cv::Mat*>(args.at(0)); //Normally, no copy

	std::vector<cv::Mat> channels;

	cv::cvtColor(picture, hsv, cv::ColorConversionCodes::COLOR_BGR2HSV_FULL);

	cv::split(hsv, channels);

	cv::minMaxLoc(channels.at(2), &min, &max);
	alpha = 1.0 / (max - min);
	beta = (-min) * alpha;
	cv::normalize(channels.at(2), channels.at(2), alpha, beta, cv::NORM_MINMAX);

	cv::equalizeHist(channels.at(2), channels.at(2));

	cv::merge(channels, hsv);

	cv::cvtColor(hsv, picture, cv::ColorConversionCodes::COLOR_HSV2BGR_FULL);

	return true;
}
