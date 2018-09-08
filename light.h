#ifndef __Raytracer__Light__
#define __Raytracer__Light__

#include <glm/glm.hpp>

class Light {
protected:
	glm::vec3 position;
	glm::vec3 couleur;
public:
	Light();

	Light(float, float, float, float, float, float);

	~Light();

	void setPosition(glm::vec3 p);

	void setColor(glm::vec3 c);

	const glm::vec3& getPosition() const;

	const glm::vec3& getCouleur() const;
};

#endif