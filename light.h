#ifndef __Raytracer__Light__
#define __Raytracer__Light__

#include <glm/glm.hpp>

class Light {
protected:
	glm::vec3 position;
	glm::vec3 couleur;
	unsigned short type;
public:
	Light() = default;

	~Light() = default;

	explicit Light(const glm::vec3& position, const glm::vec3& couleur, unsigned short type);

	explicit Light(glm::vec3&& position, glm::vec3&& couleur, unsigned short type);

	void setPosition(glm::vec3 p);

	void setColor(glm::vec3 c);

	virtual void setType(unsigned short type);

	const glm::vec3& getPosition() const;

	const glm::vec3& getCouleur() const;

	virtual unsigned short getType() const;

};

#endif