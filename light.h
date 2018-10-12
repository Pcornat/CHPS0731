#ifndef __Raytracer__Light__
#define __Raytracer__Light__

#include <glm/glm.hpp>

class Light {
protected:
	glm::highp_dvec3 position;
	glm::highp_dvec3 couleur;
public:
	Light() = default;

	~Light() = default;

	explicit Light(double, double, double, double, double, double);

	explicit Light(const glm::highp_dvec3& position, const glm::highp_dvec3& couleur);

	explicit Light(glm::highp_dvec3&& position, glm::highp_dvec3&& couleur);

	void setPosition(glm::highp_dvec3 p);

	void setColor(glm::highp_dvec3 c);

	const glm::highp_dvec3& getPosition() const;

	const glm::highp_dvec3& getCouleur() const;
};

#endif