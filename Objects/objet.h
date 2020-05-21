#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include <vector>
#include <memory>

#include <DeSerializer/deserializer.h>

class Scene;

class Material;

class Rayon;

class Intersection;

/**
 * \class Objet
 * This class exists to do polymorphism inside the code.
 */
class Objet {
protected:
	std::shared_ptr<Material> material = nullptr;

public:

	Objet() = default;

	virtual ~Objet() = default;

	/**
	 * It replaces the colour of the object, a material is better.
	 * @param material The material pointer to have.
	 */
	explicit Objet(Material *material);

	/**
	 * An objet cannot compute its intersection, it is a pure virtual member.
	 * @return a boolean value : true = intersection, false = no intersection.
	 */
	virtual bool calculIntersection(const Rayon &, const Scene &, std::vector<Intersection> &, int) const = 0;

	[[nodiscard]] const std::shared_ptr<Material> &get_material() const;

	void set_material(Material *material);

	Objet &operator=(const Objet &objet);

	Objet &operator=(Objet &&objet) noexcept;

	friend void from_json(const json &j, Objet &obj);
};


#endif 