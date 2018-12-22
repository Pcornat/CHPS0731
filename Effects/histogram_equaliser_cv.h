//
// Created by Florent on 22/12/2018.
//

#ifndef RAYTRACER_HISTOGRAM_EQUALISER_CV_H
#define RAYTRACER_HISTOGRAM_EQUALISER_CV_H


#include "effect.h"

class HistogramEqualiserCV : virtual public Effect {
public:

	/**
	 * WARNING : to use only with one argument
	 * @param args Type of argument : cv::Mat
	 * @return In this case, always true (exception will be raised if any mistakes appears).
	 */
	bool effect(void* args) override;
};


#endif //RAYTRACER_HISTOGRAM_EQUALISER_CV_H
