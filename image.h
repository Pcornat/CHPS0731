#ifndef __Raytracer__image__
#define __Raytracer__image__

#include <glm/glm.hpp>
#include <iostream>
#include <string>

class Image {
protected:
	unsigned int hauteur; // position de l'oeil
	unsigned int largeur; // Largeur de l'ecran
	glm::highp_dvec3* pixels;
public:
	Image(unsigned int, unsigned int);

	Image(std::string name);

	int getHauteur();

	int getLargeur();

	void Save(std::string);

	~Image();

	void setPixel(int, int, glm::highp_dvec3);
};

#endif