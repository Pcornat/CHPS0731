#include <memory>
#include "GeometricModel.h"

GeometricModel::GeometricModel(std::string&& name, float angle, glm::vec3&& axis) : nb_vertex(0), nb_faces(0), loader(new OBJLoader()), name(name) {
	this->loader->loadModel(this->name, *this, angle, axis);
}

GeometricModel::GeometricModel(const std::string& name, float angle, const glm::vec3& axis)
		: nb_vertex(0), nb_faces(0), loader(new OBJLoader()), name(name) {
	this->loader->loadModel(this->name, *this, angle, axis);
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
}

const std::string& GeometricModel::getName() const {
	return name;
}

GeometricModel& GeometricModel::operator=(const GeometricModel& model) {
	if (this != &model) {
		this->nb_vertex = model.nb_vertex;
		this->nb_faces = model.nb_faces;
		this->name = model.name;
		this->listVertex = model.listVertex;
		this->listFaces = model.listFaces;
		this->listCoordFaces = model.listCoordFaces;
		this->listCoords = model.listCoords;
		this->listNormals = model.listNormals;
		this->listTangents = model.listTangents;
		this->loader = std::make_unique<OBJLoader>();
	}
	return *this;
}

GeometricModel& GeometricModel::operator=(GeometricModel&& model) noexcept {
	if (this != &model) {
		this->nb_vertex = model.nb_vertex;
		this->nb_faces = model.nb_faces;
		this->name = std::move(model.name);
		this->listVertex = std::move(model.listVertex);
		this->listFaces = std::move(model.listFaces);
		this->listCoordFaces = std::move(model.listCoordFaces);
		this->listCoords = std::move(model.listCoords);
		this->listNormals = std::move(model.listNormals);
		this->listTangents = std::move(model.listTangents);
		this->loader = std::move(model.loader);
	}
	return *this;
}
