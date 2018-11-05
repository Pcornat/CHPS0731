#ifndef INTERSECTION_HPP
#define INTERSECTION_HPP

#include <glm/glm.hpp>


class Objet;

class Intersection {
private:
	float dist; // La distance à l'origine de l'intersection
	glm::vec3 normal;
	Objet* obj;        // l'objet intersecté
public:
	Intersection() = default;

	explicit Intersection(Objet* obj);

	explicit Intersection(float dist, Objet* obj);

	explicit Intersection(float dist, const glm::vec3& normal, Objet* obj);

	~Intersection() = default;

	const glm::vec3& getNormal() const;

	void setNormal(const glm::vec3& normal);

	float getDist() const;

	Objet* getObj() const;

	void setObj(Objet* obj);

	// Opérateur de tri des intersections
	int operator<(const Intersection& i) const {
		return dist < i.dist;
	}

	int operator>(const Intersection& i) const {
		return dist > i.dist;
	}
};


#endif
