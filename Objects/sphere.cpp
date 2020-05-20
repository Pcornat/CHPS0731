//
// Created by Florent on 10/09/2018.
//
#include "sphere.hpp"

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtx/intersect.hpp>

#include <intersection.h>
#include <Camera/rayon.h>
#include <Materials/material.h>
#include <Materials/phong.h>


bool Sphere::calculIntersection(const Rayon &rayon, [[maybe_unused]] const Scene &sc, std::vector<Intersection> &I, [[maybe_unused]] int rec) {
	float dist = 0.0f;
	if (!glm::intersectRaySphere(rayon.getOrigine(), rayon.vectDirection(), this->center, this->radius, dist)) {
		return false;
	}
	const glm::vec3 point = rayon.getOrigine() + (rayon.vectDirection() * dist),
			norm = glm::normalize((point - this->center) / glm::length(point - this->center));
	I.emplace_back(dist, norm, this);
	return true;
}

Sphere::Sphere(Material *material, glm::vec3 &&center, int radius) : Objet(material), center(center), radius(radius) {}

Sphere::Sphere(Material *material, const glm::vec3 &center, int radius) : Objet(material), center(center),
																		  radius(radius) {}

void from_json(const json &j, Sphere &sph) {
	from_json(j, static_cast<Objet &>(sph));
	sph.center = j.at("center").get<glm::vec3>();
	sph.radius = j.at("radius").get<int>();
}