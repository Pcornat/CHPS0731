//
// Created by Florent on 14/12/2018.
//

#include "image_cv.h"
#include <opencv2/imgcodecs.hpp>

ImageCV::ImageCV(uint32_t hauteur, uint32_t largeur) : hauteur(hauteur), largeur(largeur) {}

uint32_t ImageCV::getHauteur() const {
	return hauteur;
}

uint32_t ImageCV::getLargeur() const {
	return largeur;
}

bool ImageCV::save(std::string&& name) {
	return cv::imwrite(name, this->pixels);
}
