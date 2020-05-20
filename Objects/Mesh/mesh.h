//
// Created by Florent on 15/10/2018.
//

#ifndef PROJECT_MESH_H
#define PROJECT_MESH_H


#include "Objects/objet.h"
#include "Objects/plan.hpp"
#include "bounding_box.h"

class GeometricModel;

class Mesh : public Objet {
private:
	///Model for the mesh.
	std::shared_ptr<GeometricModel> model = nullptr;

	///Bounding box. Better for the tree of accelerating structure in the future, than a sphere.
	BoundingBox box;

	///Center of the model, where it will be.
	glm::vec3 center{};

	///Factor to make the model bigger.
	unsigned int factor = 1;

	///It creates the bounding box of the model.
	void boundingBox();

public:
	Mesh() = default;

	~Mesh() override = default;

	/**
	 * Construct a mesh with l-value.
	 * @param material @see Material
	 * @param name
	 * @param center
	 * @param factor
	 */
	explicit Mesh(Material *material, const std::string &name, const glm::vec3 &center, unsigned int factor, float angle, const glm::vec3 &axis);

	/**
	 * Construct a mesh with r-value parameters.
	 * @param material
	 * @param name
	 * @param center
	 * @param factor
	 */
	explicit Mesh(Material *material, std::string &&name, glm::vec3 &&center, unsigned int factor, float angle, glm::vec3 &&axis);

	/**
	 * R-value version
	 * Construct a mesh object without a model : you have to use the setModel method or you will have an exception.
	 * This constructor enables to have more than one object with the same 3D model : no copy of the model in the memory.
	 * @param material
	 * @param center
	 * @param factor
	 * @param angle
	 * @param axis
	 */
	explicit Mesh(Material *material, glm::vec3 &&center, uint32_t factor, float angle, glm::vec3 &&axis);

	/**
	 * L-value version
	 * Construct a mesh object without a model : you have to use the setModel method or you will have an exception.
	 * This constructor enables to have more than one object with the same 3D model : no copy of the model in the memory.
	 * @param material
	 * @param center
	 * @param factor
	 * @param angle
	 * @param axis
	 */
	explicit Mesh(Material *material, const glm::vec3 &center, uint32_t factor, float angle, const glm::vec3 &axis);

	/**
	 * Compute intersection between the model and the ray.
	 * @param rayon
	 * @param scene
	 * @param vector1
	 * @param i
	 * @return
	 */
	bool calculIntersection(const Rayon &rayon, const Scene &scene, std::vector<Intersection> &vector1, int i) override;


	/**
	 * Set the 3D model to use.
	 * @param model
	 */
	void setModel(const Mesh &model);

	[[nodiscard]] const glm::vec3 &getCenter() const;

	void setCenter(const glm::vec3 &center);

	[[nodiscard]] unsigned int getFactor() const;

	void setFactor(unsigned int factor);

	/**
	 * Moving assignment operator
	 * @param mesh
	 * @return
	 */
	Mesh &operator=(Mesh &&mesh) noexcept;
};


#endif //PROJECT_MESH_H
