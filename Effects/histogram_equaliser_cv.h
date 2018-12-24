//
// Created by Florent on 22/12/2018.
//

#ifndef RAYTRACER_HISTOGRAM_EQUALISER_CV_H
#define RAYTRACER_HISTOGRAM_EQUALISER_CV_H


#include "effect.h"
#include <opencv2/core/mat.hpp>

class HistogramEqualiserCV : virtual public Effect {
public:

	/**
	 * WARNING : to use only with one argument. User an initilizer list with boost::any
	 * @param args The list of arguments.
	 * @return Always true or exception
	 */
	bool effect(const std::vector<void*>& args) override;
};


#endif //RAYTRACER_HISTOGRAM_EQUALISER_CV_H
