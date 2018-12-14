//
// Created by Florent on 14/12/2018.
//

#include "gl_mto_cv.h"

#include <glm/gtc/type_ptr.hpp>
#include <stdexcept>

void GLMtoCV::fromGLMtoCV(const glm::mat4& glmmat, cv::Mat4f& cvmat) {
	if (cvmat.cols != 4 || cvmat.rows != 4) {
		cvmat = cv::Mat(4, 4, CV_32F);
	}
	memcpy(cvmat.data, glm::value_ptr(glmmat), 16 * sizeof(float));
	cvmat = cvmat.t();
}

void fromCVtoGLM(const cv::Mat4f& cvmat, glm::mat4& glmmat) {
	if (cvmat.cols != 4 || cvmat.rows != 4 || cvmat.type() != CV_32FC1) {
		throw std::runtime_error("Exception : matrix conversion.\n");
	}
	memcpy(glm::value_ptr(glmmat), cvmat.data, 16 * sizeof(float));
	glmmat = glm::transpose(glmmat);
}