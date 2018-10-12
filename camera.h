#ifndef __Raytracer__camera__
#define __Raytracer__camera__

#include <glm/glm.hpp>
#include "scene.h"
#include "rayon.h"

class Image;

class Camera {
protected:
	glm::highp_dvec3 centre; // position de l'oeil
	double largeur; // Largeur de l'ecran
	double hauteur; // Hauteur de l'ecran
	double dist; // Distance focale de la camera
	glm::highp_dvec3 dir; // Direction de vue de la camera
	glm::highp_dvec3 haut; // Vecteur definissant l'orientation de la "tete" de la camera

public:
	Camera() {
		centre = glm::highp_dvec3(0, 0, -3);
		largeur = 2;
		hauteur = 2 * 3.0 / 4.0;
		dist = 10;
		dir = glm::highp_dvec3(0, 0, 1);
		haut = glm::highp_dvec3(0, 1, 0);
	}

	glm::highp_dvec3 Centre() const {
		return centre;
	}

	double Largeur() const {
		return largeur;
	}

	double Hauteur() const {
		return hauteur;
	}

	double Dist() const {
		return dist;
	}

	glm::highp_dvec3 Dir() const {
		return dir;
	}

	glm::highp_dvec3 Haut() const {
		return haut;
	}

	void Centre(const glm::highp_dvec3& c) {
		centre = c;
	}

	void Largeur(double l) {
		largeur = l;
	}

	void Hauteur(double h) {
		hauteur = h;
	}

	void Dist(double d) {
		dist = d;
	}

	void Dir(const glm::highp_dvec3& d) {
		dir = d;
		dir = glm::normalize(dir);
	}

	void Haut(const glm::highp_dvec3& h);

	void Calculer_image(Image&, Scene& sc, int) const;
};

#endif