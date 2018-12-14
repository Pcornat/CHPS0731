//
// Created by Florent on 14/12/2018.
//

#ifndef PROJECT_IMAGE_CV_H
#define PROJECT_IMAGE_CV_H

#include <opencv2/core/mat.hpp>

class ImageCV {
protected:
	cv::Mat4f pixels;
	std::uint32_t hauteur;
	std::uint32_t largeur;

public:
	ImageCV() = default;

	explicit ImageCV(uint32_t hauteur, uint32_t largeur);

	virtual ~ImageCV() = default;

	uint32_t getHauteur() const;

	uint32_t getLargeur() const;

	/**
	 * Used to save the image.
	 * @param name the name of the picture
	 * @return true : saved, else not saved and error.
	 */
	bool save(std::string&& name);
};


#endif //PROJECT_IMAGE_CV_H
