//
// Created by Florent on 15/10/2018.
//

#ifndef PROJECT_MESH_H
#define PROJECT_MESH_H


#include "objet.h"
#include "GeometricModel.h"
#include "plan.hpp"
#include "bounding_box.h"

class Mesh : public Objet {
private:
	///Model for the mesh.
	GeometricModel model;

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

	/**
	 * Construct a mesh with l-value.
	 * @param material @see Material
	 * @param name
	 * @param center
	 * @param factor
	 */
	explicit Mesh(Material* material, const std::string& name, const glm::vec3& center, unsigned int factor, float angle, const glm::vec3& axis);

	/**
	 * Construct a mesh with r-value parameters.
	 * @param material
	 * @param name
	 * @param center
	 * @param factor
	 */
	explicit Mesh(Material* material, std::string&& name, glm::vec3&& center, unsigned int factor, float angle, glm::vec3&& axis);

	~Mesh() override;

	/**
	 * Compute intersection between the model and the ray.
	 * @param rayon
	 * @param scene
	 * @param vector1
	 * @param i
	 * @return
	 */
	bool calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& vector1, int i) override;

	void fromJson(const FromJson::json& objet) const override;

	/**
	 * Moving assignment operator
	 * @param mesh
	 * @return
	 */
	Mesh& operator=(Mesh&& mesh) noexcept;
};


#endif //PROJECT_MESH_H
