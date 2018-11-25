#ifndef __Raytracer__image__
#define __Raytracer__image__

#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <vector>

class Image {
protected:
	std::vector<glm::vec3> pixels;
	std::size_t hauteur; // position de l'oeil
	std::size_t largeur; // Largeur de l'ecran
public:
	Image(unsigned int, unsigned int);

	Image(std::string name);

	virtual ~Image() = default;

	size_t getHauteur() const;

	size_t getLargeur() const;

	void Save(std::string);

	void setPixel(int, int, glm::vec3);
};

#endif