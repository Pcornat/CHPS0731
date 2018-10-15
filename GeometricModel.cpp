#include <iostream>
#include "GeometricModel.h"
#include "OBJLoader.h"

GeometricModel::GeometricModel(std::string name) : nb_faces(0), nb_vertex(0), m_Name(name), loader(new OBJLoader()) {
	this->loader->loadModel(name, this);
};