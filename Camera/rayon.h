#ifndef __Raytracer__ray__
#define __Raytracer__ray__

#include <glm/glm.hpp>
#include "scene.h"
#include "intersection.h"

class Rayon {
protected:

	glm::vec3 origine;
	glm::vec3 direction;

public:
	Rayon() = default;

	explicit Rayon(const glm::vec3& origine, const glm::vec3& direction);

	const glm::vec3& getOrigine() const {
		return origine;
	}

	const glm::vec3& vectDirection() const {
		return direction;
	}


	void setOrigine(const glm::vec3& o) {
		origine = o;
	}

	void setOrigine(glm::vec3&& o) {
		Rayon::origine = o;
	}

	void setVectDirection(const glm::vec3& v) {
		direction = glm::normalize(v);
	}

	void setVectDirection(glm::vec3&& v) {
		Rayon::direction = glm::normalize(v);
	}

	glm::vec3 lancer(const Scene& sc, int complexite) const;

	bool shadowRay(const Scene& sc, float distLum, int complexite);
};

#endif