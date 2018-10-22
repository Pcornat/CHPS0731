
#ifndef _GEOMETRIC_MODEL_H
#define _GEOMETRIC_MODEL_H

#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include "OBJLoader.h"

class GeometricModel {
	friend OBJLoader;
private:
	struct Face {
		int s1, s2, s3;
	};
	unsigned int nb_vertex;
	unsigned int nb_faces;
	std::vector<glm::vec3> listVertex;
	std::vector<Face> listFaces;
	std::vector<Face> listCoordFaces;
	std::vector<glm::vec3> listNormals;
	std::vector<glm::vec3> listCoords;
	std::vector<glm::vec4> listTangents;
	std::unique_ptr<OBJLoader> loader;
	std::string name;

public:
	GeometricModel() = default;

	explicit GeometricModel(const std::string& name);

	explicit GeometricModel(std::string&& name);

	~GeometricModel() = default;

	const std::vector<glm::vec3>& getListVertex() const;

	const std::vector<Face>& getListFaces() const;

	const std::vector<Face>& getListCoordFaces() const;

	const std::vector<glm::vec3>& getListNormals() const;

	const std::vector<glm::vec3>& getListCoords() const;

	const std::vector<glm::vec4>& getListTangents() const;

	GeometricModel& operator=(const GeometricModel& model);

	/**
	 * Moving assignment operator.
	 * @param model Rvalue model to move.
	 * @return the new GeometricModel.
	 */
	GeometricModel& operator=(GeometricModel&& model) noexcept;
};


#endif
