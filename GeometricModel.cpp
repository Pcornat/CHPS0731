#include <iostream>
#include "GeometricModel.h"
#include "OBJLoader.h"

GeometricModel::GeometricModel(std::string name) : nb_faces(0), nb_vertex(0), m_Name(name), loader(new OBJLoader()) {
	this->loader->loadModel(name, *this);
}

const std::vector<glm::vec3>& GeometricModel::getListVertex() const {
	return listVertex;
}

const std::vector<GeometricModel::Face>& GeometricModel::getListFaces() const {
	return listFaces;
}

const std::vector<GeometricModel::Face>& GeometricModel::getListCoordFaces() const {
	return listCoordFaces;
}

const std::vector<glm::vec3>& GeometricModel::getListNormals() const {
	return listNormals;
}

const std::vector<glm::vec3>& GeometricModel::getListCoords() const {
	return listCoords;
}

const std::vector<glm::vec4>& GeometricModel::getListTangents() const {
	return listTangents;
};