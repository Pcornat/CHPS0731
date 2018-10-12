#ifndef __Raytracer__ray__
#define __Raytracer__ray__

#include <glm/glm.hpp>
#include "scene.h"
#include "intersection.h"

class Rayon {
protected:

	glm::highp_dvec3 orig;
	glm::highp_dvec3 vect;

public:
	Rayon() = default;

	explicit Rayon(const glm::highp_dvec3& orig, const glm::highp_dvec3& vect);

	glm::highp_dvec3 Orig() const {
		return orig;
	}

	glm::highp_dvec3 Vect() const {
		return vect;
	}


	void Orig(const glm::highp_dvec3& o) {
		orig = o;
	}

	void Vect(const glm::highp_dvec3& v) {
		vect = glm::normalize(v);
	}

	glm::highp_dvec3 Lancer(const Scene& sc, int complexite) const;

	bool shadowRay(const Scene& sc, double distLum);
};

#endif