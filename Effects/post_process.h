//
// Created by Florent on 20/11/2018.
//

#ifndef PROJECT_POST_PROCESS_H
#define PROJECT_POST_PROCESS_H

#include <glm/glm.hpp>
#include <vector>
#include <opencv2/core/mat.hpp>

namespace postProcess {

	void TONE_MAPPING_UCHIMURA_PHONG(glm::vec3& input);

	void TONE_MAPPING_LOTTES_PHONG(glm::vec3& input);

	void TONE_MAPPING_SIMPLE_IMAGE(std::vector<glm::vec3>& pixels);

	/**
	 * IT doesn't work yet.
	 * @param picture An OpenCV picture to apply an effect on it (see the method name).
	 */
	void equalizeHist(cv::Mat& picture);

}


#endif //PROJECT_POST_PROCESS_H
