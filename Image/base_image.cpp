//
// Created by Florent on 15/12/2018.
//

#include "base_image.h"

uint32_t BaseImage::getHauteur() const {
	return this->hauteur;
}

uint32_t BaseImage::getLargeur() const {
	return this->largeur;
}

BaseImage::BaseImage(uint32_t hauteur, uint32_t largeur) : hauteur(hauteur), largeur(largeur) {}
