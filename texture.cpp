//
// Created by Florent on 23/10/2018.
//

#include "texture.h"
#include "mesh.h"

Texture::Texture(bool refraction) : Material(refraction) {}

glm::vec3 Texture::computeColour(const Intersection& I, const glm::vec3& point, const Scene& s, const Rayon& r, int rec) {
	Mesh* mesh = reinterpret_cast<Mesh*>(I.getObj());

	return glm::vec3();
}
