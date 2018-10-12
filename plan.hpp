//
// Created by postaron on 22/09/18.
//

#ifndef RAYTRACE_BASE_PLAN_HPP
#define RAYTRACE_BASE_PLAN_HPP


#include "objet.h"
#include "rayon.h"

/**
 * \class Plan
 * @brief Un plan affichable. Définit par son vecteur normal + distance de la caméra.
 */
class Plan : public Objet {
private:
	glm::highp_dvec3 orig;
	glm::highp_dvec3 normal;

public:
	Plan() = default;

	~Plan() override;

	explicit Plan(Material* material, const glm::highp_dvec3& orig, const glm::highp_dvec3& normal);

	explicit Plan(Material* material, glm::highp_dvec3&& orig, glm::highp_dvec3&& normal);

	bool calculIntersection(const Rayon&, const Scene&, std::vector<Intersection>&, int) override;
};


#endif //RAYTRACE_BASE_PLAN_HPP
