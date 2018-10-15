#ifndef _GEOMETRIC_LOADER_H
#define _GEOMETRIC_LOADER_H

#include <string>

class GeometricModel;

class OBJLoader {
public:
	OBJLoader() = default;

	~OBJLoader() = default;

	bool loadModel(const std::string& name, GeometricModel& model);

private:
	void setupForTextureCoordinates(GeometricModel& model);

	void computeNormals(GeometricModel& model);

	void computeTangents(GeometricModel& model);
};

#endif
