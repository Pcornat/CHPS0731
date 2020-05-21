#ifndef INTERSECTION_HPP
#define INTERSECTION_HPP

#include <cmath>
#include <glm/vec3.hpp>

class Objet;

class Intersection {
private:
	float dist; // La distance à l'origine de l'intersection
	glm::vec3 normal;
	const Objet *obj;        // l'objet intersecté
public:
	Intersection() = default;

	explicit Intersection(const Objet *obj);

	explicit Intersection(float dist, const Objet *obj);

	explicit Intersection(float dist, const glm::vec3 &normal, const Objet *obj);

	~Intersection() = default;

	[[nodiscard]] const glm::vec3 &getNormal() const;

	void setNormal(const glm::vec3 &normal);

	[[nodiscard]] float getDist() const;

	[[nodiscard]] const Objet *getObj() const;

	// Opérateur de tri des intersections
	bool operator<(const Intersection &i) const {
		return std::isless(dist, i.dist);
	}

	bool operator>(const Intersection &i) const {
		return std::isgreater(dist, i.dist);
	}
};


#endif
