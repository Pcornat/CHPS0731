//
// Created by Florent on 22/12/2018.
//

#include "histogram_equaliser_cv.h"
#include <opencv2/core/mat.hpp>

bool HistogramEqualiserCV::effect(void* args) {
	auto& mat = *reinterpret_cast<cv::Mat*>(args);
	return false;
}
