#ifndef __Raytracer__ray__
#define __Raytracer__ray__

#define GLM_FORCE_INLINE
#define GLM_FORCE_XYZW_ONLY

#include <glm/vec3.hpp>
#include <glm/geometric.hpp>

class Scene;

class Rayon {
protected:

	glm::vec3 origine{ 0 };

	glm::vec3 direction{ 0 };

public:
	Rayon() = default;

	explicit Rayon(const glm::vec3 &origine, const glm::vec3 &direction);

	[[nodiscard]] const glm::vec3 &getOrigine() const {
		return origine;
	}

	[[nodiscard]] const glm::vec3 &vectDirection() const {
		return direction;
	}


	void setOrigine(const glm::vec3 &o) {
		origine = o;
	}

	void setOrigine(glm::vec3 &&o) {
		Rayon::origine = o;
	}

	void setVectDirection(const glm::vec3 &v) {
		direction = glm::normalize(v);
	}

	void setVectDirection(glm::vec3 &&v) {
		Rayon::direction = glm::normalize(v);
	}

	/**
	 *
	 * @param sc The scene to display
	 * @param complexite depth of recursivity for reflection.
	 * @return
	 */
	[[nodiscard]] glm::vec3 lancer(const Scene &sc, int complexite) const;

	/**
	 * @todo Take in account the light : no real plane light is on screen. There's a big problem.
	 * @param sc The scene to display
	 * @param distLum The distance from the point to the light.
	 * @param complexite depth of recursivity for reflection.
	 * @return
	 */
	bool shadowRay(const Scene &sc, float distLum, int complexite);
};

#endif