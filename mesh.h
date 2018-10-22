//
// Created by Florent on 15/10/2018.
//

#ifndef PROJECT_MESH_H
#define PROJECT_MESH_H


#include "objet.h"
#include "GeometricModel.h"
#include "plan.hpp"

class Mesh : public Objet {
private:
	///Model for the mesh.
	GeometricModel model;

	///Globing box. Better for the tree of accelerating structure.
	std::array<Plan, 6> box;

	///Center of the model, where it will be.
	glm::vec3 center;

	///Factor to make the model bigger.
	unsigned int factor;

	/*
	 * Private method under
	 */
	void globingBox();

public:
	Mesh() = default;

	explicit Mesh(Material* material, const std::string& name, const glm::vec3& center, unsigned int factor);

	explicit Mesh(Material* material, std::string&& name, glm::vec3&& center, unsigned int factor);

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

	Mesh& operator=(Mesh&& mesh) noexcept;
};


#endif //PROJECT_MESH_H
