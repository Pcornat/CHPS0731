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
	glm::vec3 orig;
	glm::vec3 normal;

public:
	Plan() = default;

	~Plan() { if (this->material != nullptr) delete material; }

	explicit Plan(float r, float g, float b, float xOrig, float yOrig, float zOrig, float x, float y, float z);

	explicit Plan(Material* material, float xOrig, float yOrig, float zOrig, float x, float y, float z);

	explicit Plan(Material* material, const glm::vec3& orig, const glm::vec3& normal);

	explicit Plan(Material* material, glm::vec3&& orig, glm::vec3&& normal);

	explicit Plan(float xOrig, float yOrig, float zOrig, float x, float y, float z);

	explicit Plan(const glm::vec3& color, const glm::vec3& orig, const glm::vec3& normal);

	explicit Plan(glm::vec3&& color, glm::vec3&& orig, glm::vec3&& normal);

	bool calculIntersection(const Rayon&, const Scene&, std::vector<Intersection>&, int) override;
};


#endif //RAYTRACE_BASE_PLAN_HPP
