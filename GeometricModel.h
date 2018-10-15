
#ifndef _GEOMETRIC_MODEL_H
#define _GEOMETRIC_MODEL_H

#include <glm/glm.hpp>
#include <vector>
#include <memory>
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
	std::string m_Name;

public:
	GeometricModel() = default;

	explicit GeometricModel(std::string gname);

	~GeometricModel() = default;

	const std::vector<glm::vec3>& getListVertex() const;

	const std::vector<Face>& getListFaces() const;

	const std::vector<Face>& getListCoordFaces() const;

	const std::vector<glm::vec3>& getListNormals() const;

	const std::vector<glm::vec3>& getListCoords() const;

	const std::vector<glm::vec4>& getListTangents() const;
};


#endif
