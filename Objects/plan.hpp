//
// Created by postaron on 22/09/18.
//

#ifndef RAYTRACE_BASE_PLAN_HPP
#define RAYTRACE_BASE_PLAN_HPP


#include "objet.h"

#define GLM_FORCE_INLINE
#define GLM_FORCE_XYZW_ONLY

#include <glm/vec3.hpp>

class Rayon;

/**
 * \class Plan
 * @brief Un plan affichable. Définit par son vecteur normal + distance de la caméra.
 */
class Plan : public Objet {
private:
	glm::vec3 orig;
	glm::vec3 normal;

public:
	Plan() = default;

	~Plan() override = default;

	explicit Plan(Material *material, const glm::vec3 &orig, const glm::vec3 &normal);

	explicit Plan(Material *material, glm::vec3 &&orig, glm::vec3 &&normal);

	bool calculIntersection(const Rayon &, const Scene &, std::vector<Intersection> &, int) const override;

	friend void from_json(const json &j, Plan &plan);
};


#endif //RAYTRACE_BASE_PLAN_HPP
