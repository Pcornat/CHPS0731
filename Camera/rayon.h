#ifndef __Raytracer__ray__
#define __Raytracer__ray__

#include <glm/glm.hpp>
#include "scene.h"
#include "intersection.h"

class Rayon {
protected:

	glm::vec3 orig;
	glm::vec3 vect;

public:
	Rayon() = default;

	explicit Rayon(const glm::vec3& orig, const glm::vec3& vect);

	glm::vec3 Orig() const {
		return orig;
	}

	glm::vec3 Vect() const {
		return vect;
	}


	void Orig(const glm::vec3& o) {
		orig = o;
	}

	void Orig(glm::vec3&& o) {
		Rayon::orig = o;
	}

	void Vect(const glm::vec3& v) {
		vect = glm::normalize(v);
	}

	void Vect(glm::vec3&& v) {
		Rayon::vect = glm::normalize(v);
	}

	glm::vec3 Lancer(const Scene& sc, int complexite) const;

	bool shadowRay(const Scene& sc, float distLum, int complexite);
};

#endif