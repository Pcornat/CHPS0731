#ifndef _GEOMETRIC_LOADER_H
#define _GEOMETRIC_LOADER_H

#include <string>

#define GLM_FORCE_XYZW_ONLY
#define GLM_FORCE_INLINE

#include <glm/vec3.hpp>

class GeometricModel;

class OBJLoader {
public:
	OBJLoader() = default;

	~OBJLoader() = default;

	bool loadModel(const std::string &name, GeometricModel &model, float angle, const glm::vec3 &axis);

	bool loadModel(const std::string &name, GeometricModel &model, float angle, glm::vec3 &&axis);

private:
	void setupForTextureCoordinates(GeometricModel &model);

	void computeNormals(GeometricModel &model);

	void computeTangents(GeometricModel &model);
};

#endif
