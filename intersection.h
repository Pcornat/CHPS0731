#ifndef INTERSECTION_HPP
#define INTERSECTION_HPP

#include <glm/glm.hpp>


class Objet;

class Intersection {
private:
	double dist; // La distance à l'origine de l'intersection
	glm::highp_dvec3 normal;
	Objet* obj;        // l'objet intersecté
public:
	Intersection() = default;

	explicit Intersection(Objet* obj);

	explicit Intersection(double dist, Objet* obj);

	explicit Intersection(double dist, const glm::highp_dvec3& normal, Objet* obj);

	~Intersection() = default;

	const glm::highp_dvec3& getNormal() const;

	void setNormal(const glm::highp_dvec3& normal);

	double getDist() const;

	Objet* getObj() const;

	// Opérateur de tri des intersections
	int operator<(const Intersection& i) const {
		return dist < i.dist;
	}

	int operator>(const Intersection& i) const {
		return dist > i.dist;
	}
};


#endif
