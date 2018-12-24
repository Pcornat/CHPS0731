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

BaseImage::BaseImage(uint32_t hauteur, uint32_t largeur) : effects(), hauteur(hauteur), largeur(largeur) {}

BaseImage::BaseImage(const std::vector<Effect*>& effects, uint32_t hauteur, uint32_t largeur) : effects(effects), hauteur(hauteur),
																								largeur(largeur) {}

BaseImage::BaseImage(std::initializer_list<Effect*> effects, uint32_t hauteur, uint32_t largeur) : effects(effects), hauteur(hauteur),
																								   largeur(largeur) {}

const std::vector<Effect*>& BaseImage::getEffects() const {
	return effects;
}

void BaseImage::addEffect(Effect* effect) {
	this->effects.push_back(effect);
}
