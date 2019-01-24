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
	std::shared_ptr<GeometricModel> model{nullptr};

	///Bounding box. Better than a sphere. I don't know if it's useful with a kd-tree.
	BoundingBox box;

	///Center of the model, where it will be.
	glm::vec3 center{0.f, 0.f, 0.f};

	///Factor to make the model bigger.
	uint32_t factor{1};

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
	 * @param angle
	 * @param axis
	 */
	explicit Mesh(Material* material,
				  const std::string& name,
				  const glm::vec3& center,
				  uint32_t factor,
				  float angle = 180.f,
				  const glm::vec3& axis = glm::vec3(0.f, 1.f, 0.f));

	/**
	 * Construct a mesh with r-value parameters.
	 * @param material
	 * @param name
	 * @param center
	 * @param factor
	 * @param angle
	 * @param axis
	 */
	explicit Mesh(Material* material,
				  std::string&& name,
				  glm::vec3&& center,
				  uint32_t factor,
				  float angle = 180.f,
				  glm::vec3&& axis = glm::vec3(0.f, 1.f, 0.f));

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
	explicit Mesh(Material* material, glm::vec3&& center, uint32_t factor, float angle = 180.f, glm::vec3&& axis = glm::vec3(0.f, 1.f, 0.f));

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
	explicit Mesh(Material* material,
				  const glm::vec3& center,
				  uint32_t factor,
				  float angle = 180.f,
				  const glm::vec3& axis = glm::vec3(0.f, 1.f, 0.f));

	~Mesh() override = default;

	/**
	 * Compute intersection between the model and the ray.
	 * @param rayon
	 * @param scene
	 * @param vector1
	 * @param i
	 * @return
	 */
	bool calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& vector1, int i) override;


	/**
	 * Sets the 3D model to use.
	 * @param model
	 */
	void setModel(const Mesh& model);

	const glm::vec3& getCenter() const;

	void setCenter(const glm::vec3& center);

	uint32_t getFactor() const;

	void setFactor(uint32_t factor);

	/**
	 * Copy assignment operator
	 * @param mesh
	 * @return
	 */
	Mesh& operator=(const Mesh& mesh);

	/**
	 * Moving assignment operator
	 * @param mesh
	 * @return
	 */
	Mesh& operator=(Mesh&& mesh) noexcept;
};


#endif //PROJECT_MESH_H
