#ifndef __Raytracer__camera__
#define __Raytracer__camera__

#include <glm/glm.hpp>
#include <Image/base_image.h>
#include "scene.h"
#include "rayon.h"

class ImageGLM;

class Camera {
protected:
	glm::vec3 centre; // position de l'oeil
	float largeur; // Largeur de l'ecran
	float hauteur; // Hauteur de l'ecran
	float dist; // Distance focale de la camera
	glm::vec3 dir; // Direction de vue de la camera
	glm::vec3 haut; // Vecteur definissant l'orientation de la "tete" de la camera

public:
	Camera() : centre(glm::vec3(0, 0, -3)), largeur(2), hauteur(2 * 9.0f / 16.0f), dist(1.0f), dir(glm::vec3(0, 0, 1)), haut(glm::vec3(0, 1, 0)) {}

	glm::vec3 Centre() const {
		return centre;
	}

	float Largeur() const {
		return largeur;
	}

	float Hauteur() const {
		return hauteur;
	}

	float Dist() const {
		return dist;
	}

	glm::vec3 Dir() const {
		return dir;
	}

	glm::vec3 Haut() const {
		return haut;
	}

	void Centre(const glm::vec3& c) {
		centre = c;
	}

	void Largeur(float l) {
		largeur = l;
	}

	void Hauteur(float h) {
		hauteur = h;
	}

	void Dist(float d) {
		dist = d;
	}

	void Dir(const glm::vec3& d) {
		dir = d;
		dir = glm::normalize(dir);
	}

	void setHaut(const glm::vec3& h);

	void Calculer_image(BaseImage* const im, Scene& sc, int complexite) const;
};

#endif