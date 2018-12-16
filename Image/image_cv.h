//
// Created by Florent on 14/12/2018.
//

#ifndef PROJECT_IMAGE_CV_H
#define PROJECT_IMAGE_CV_H

#include "base_image.h"
#include <opencv2/core/mat.hpp>
#include <glm/vec3.hpp>

class ImageCV : public BaseImage {
protected:
	///It is the picture
	cv::Mat pixels;

	///It is the type of the matrix : byte with three channel : RGB (255 value, a real picture)
	static const int32_t type = CV_8UC4;

	///It is not initialized by default.
	bool initialized = false;

public:
	/**
	 *
	 */
	ImageCV() = default;

	/**
	 *
	 * @param hauteur
	 * @param largeur
	 */
	explicit ImageCV(uint32_t hauteur, uint32_t largeur);

	~ImageCV() override = default;

	/**
	 *
	 * @param hauteur
	 * @param largeur
	 */
	void setSize(uint32_t hauteur, uint32_t largeur);

	/**
	 * Used to save the image.
	 * @param name the name of the picture
	 * @return true : saved, else not saved and error.
	 */
	bool save(const std::string& name) override;

	/**
	 * It sets the pixel correctly.
	 * @param x
	 * @param y
	 * @param pixel
	 */
	void setPixel(uint32_t x, uint32_t y, const glm::vec3& pixel) override;
};


#endif //PROJECT_IMAGE_CV_H
