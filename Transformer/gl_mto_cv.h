//
// Created by Florent on 14/12/2018.
//

#ifndef PROJECT_GL_MTO_CV_H
#define PROJECT_GL_MTO_CV_H

#include <opencv2/core/mat.hpp>
#include <glm/glm.hpp>

class GLMtoCV {
public:
	static void fromGLMtoCV(const glm::mat4& glmmat, cv::Mat4f& cvmat);

	static void fromCVtoGLM(const cv::Mat4f& cvmat, glm::mat4& glmmat);
};


#endif //PROJECT_GL_MTO_CV_H
