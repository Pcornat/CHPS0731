#include "mesh.h"
#include <intersection.h>
#include <Camera/rayon.h>
#include <Materials/material.h>
#include <Objects/Mesh/GeometricModel.h>

#include <glm/vec2.hpp>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtx/intersect.hpp>

bool Mesh::calculIntersection(const Rayon &rayon,
							  [[maybe_unused]] const Scene &scene,
							  std::vector<Intersection> &I,
							  [[maybe_unused]] const int complexite) const {
	const auto &listVertex(model->getListVertex());
	const auto &listNormals(model->getListNormals());
	bool inter = false;
	//if (this->box.calculIntersection(rayon, scene, I, complexite)) {
	for (const auto &face : model->getListFaces()) {
		float dist = 0.f;
		glm::vec2 baryPos;
		glm::vec3 facteur(this->factor),
				pointA = facteur * listVertex.at(static_cast<unsigned long>(face.s1)) + this->center,
				pointB = facteur * listVertex.at(static_cast<unsigned long>(face.s2)) + this->center,
				pointC = facteur * listVertex.at(static_cast<unsigned long>(face.s3)) + this->center;
		if ((inter = glm::intersectRayTriangle(rayon.getOrigine(), rayon.vectDirection(), pointA, pointB, pointC, baryPos, dist)) &&
			std::isgreater(dist, 0.f)) {
			I.emplace_back(dist,
						   listNormals.at(static_cast<unsigned long>(face.s2)) * baryPos.x +
						   listNormals.at(static_cast<unsigned long>(face.s3)) * baryPos.y +
						   listNormals.at(static_cast<unsigned long>(face.s1)) * (1 - baryPos.x - baryPos.y),
						   this);
		}
	}
	return inter;
}

Mesh::Mesh(Material *material, const std::string &name, const glm::vec3 &center, unsigned int factor, float angle, const glm::vec3 &axis)
		: Objet(material), model(new GeometricModel(name, angle, axis)), center(center), factor(factor) {
	this->boundingBox();
}

Mesh::Mesh(Material *material, std::string &&name, glm::vec3 &&center, unsigned int factor, float angle, glm::vec3 &&axis)
		: Objet(material), model(new GeometricModel(name, angle, axis)), center(center), factor(factor) {
	this->boundingBox();
}

Mesh::Mesh(Material *material, glm::vec3 &&center, uint32_t factor, float angle, glm::vec3 &&axis)
		: Objet(material), model(nullptr), center(center), factor(factor) {}

Mesh::Mesh(Material *material, const glm::vec3 &center, uint32_t factor, float angle, const glm::vec3 &axis)
		: Objet(material), model(nullptr), center(center), factor(factor) {}

Mesh &Mesh::operator=(Mesh &&mesh) noexcept {
	if (this != &mesh) {
		this->model = std::move(mesh.model);
		this->box = mesh.box;
		this->center = mesh.center;
		this->factor = mesh.factor;
		this->material = std::move(mesh.material);
		mesh.material = nullptr;
	}
	return *this;
}

void Mesh::boundingBox() {
	float xMin = std::numeric_limits<float>::max(), yMin = std::numeric_limits<float>::max(), zMin = std::numeric_limits<float>::max(),
			xMax = 0, yMax = 0, zMax = 0;
	const auto &listVertex(this->model->getListVertex());
	const auto &listFace(model->getListFaces());
	//Lambda function to code faster.
	const auto min = [](float a, float b) {
		if (std::isless(a, b))
			return a;
		else
			return b;
	};
	const auto max = [](float a, float b) {
		if (std::isgreater(a, b))
			return a;
		else
			return b;
	};

#pragma omp parallel for default(shared) reduction(min: xMin) reduction(min: yMin) reduction(min: zMin) reduction(max: xMax) reduction(max: yMax) reduction(max: zMax)
	for (std::size_t i = 0; i < listFace.size(); ++i) {
		const auto &vertexS1(listVertex.at(static_cast<unsigned long>(listFace.at(i).s1))),
				vertexS2(listVertex.at(static_cast<unsigned long>(listFace.at(i).s2))),
				vertexS3(listVertex.at(static_cast<unsigned long>(listFace.at(i).s3)));

		/*
		 * Trouver le xMin.
		 */
		xMin = min(xMin, vertexS1.x);
		xMin = min(xMin, vertexS2.x);
		xMin = min(xMin, vertexS3.x);

//		xMin = std::isless(xMin, vertexS1.x) ? xMin : vertexS1.x;
//		xMin = min(xMin, vertexS2.x);
//		xMin = min(xMin, vertexS3.x);

		/*
		 * Trouver le yMin
		 */
		yMin = min(yMin, vertexS1.y);
		yMin = min(yMin, vertexS2.y);
		yMin = min(yMin, vertexS3.y);

		/*
		 * Trouver le zMin
		 */
		zMin = min(zMin, vertexS1.z);
		zMin = min(zMin, vertexS2.z);
		zMin = min(zMin, vertexS3.z);

		/*
		 * Trouver le xMax
		 */
		xMax = max(xMax, vertexS1.x);
		xMax = max(xMax, vertexS2.x);
		xMax = max(xMax, vertexS3.x);

		/*
		 * Trouver le yMax
		 */
		yMax = max(yMax, vertexS1.y);
		yMax = max(yMax, vertexS2.y);
		yMax = max(yMax, vertexS3.y);

		/*
		 * Trouver le zMax
		 */
		zMax = max(zMax, vertexS1.z);
		zMax = max(zMax, vertexS2.z);
		zMax = max(zMax, vertexS3.z);
	}
	this->box = BoundingBox(xMin, yMin, zMin, xMax, yMax, zMax);
}

const glm::vec3 &Mesh::getCenter() const {
	return center;
}

void Mesh::setCenter(const glm::vec3 &center) {
	Mesh::center = center;
}

unsigned int Mesh::getFactor() const {
	return factor;
}

void Mesh::setFactor(unsigned int factor) {
	Mesh::factor = factor;
}

void Mesh::setModel(const Mesh &model) {
	if (this != &model) {
		Mesh::model = model.model->shared_from_this();
		this->boundingBox();
	}
}
