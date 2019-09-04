//
// Created by kevin on 12/09/18.
//

#ifndef CHPS0731_PHONG_H
#define CHPS0731_PHONG_H


#include "material.h"

/**
 * \class Phong
 * This class is a material, it defines the texture, the representation of an object.
 * This material is based on the phong model.
 */

class Phong : public Material {
protected:
	///Ambient coeff
	glm::vec3 ka; //(R, G, B)

	///Diff coeff
	glm::vec3 kd; //(R, G, B)

	///Specular coeff
	float ks;

	///Reflection percentage
	float reflection;

public:
	Phong() = default;

	/**
	 * \brief Deserialize from json file.
	 * \param json
	 */
	explicit Phong(const Deserializer::json &json);

	~Phong() override = default;

	/**
	 * Construct a phong material.
	 * \param refraction Refraction or not ? (spoiler alert : not implemented)
	 * \param ka Ambient coeff
	 * \param kd Diffusion coeff
	 * \param ks Specular coeff
	 * \param reflection Reflection coeff
	 */
	explicit Phong(bool refraction, const glm::vec3 &ka, const glm::vec3 &kd, float ks, float reflection);

	/**
	 * Construct a phong material with r-value.
	 * \param refraction Refraction or not ? (spoiler alert : not implemented)
	 * \param ka Ambient coef
	 * \param kd Diffusion coef
	 * \param ks Specular coef
	 * \param reflection Reflection coeff
	 */
	explicit Phong(bool refraction, glm::vec3 &&ka, glm::vec3 &&kd, float ks, float reflection);

	/**
	 * Computes colour from the phong model. It also takes care of the reflection.
	 * Now, it computes the shadow, soft-shadows to be precise.
	 * \todo : tone mapping for the colours (it should be in [0; 1] interval and not in [0; infinity])
	 * \param I Inntersection from the ray and the object.
	 * \param point The point of the intersection
	 * \param s The scene where rays are launched
	 * \param rayon The ray that touched the object
	 * \param rec The reflection depth
	 * \return The object's colour (the normal vector to make it simple)
	 */
	glm::vec3 computeColour(const Intersection &I, const glm::vec3 &point, const Scene &s, const Rayon &rayon, int rec) override;
};


#endif //CHPS0731_PHONG_H
