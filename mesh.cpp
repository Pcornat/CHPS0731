#include "mesh.h"

bool Mesh::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int complexite) {
	auto& listVertex(model.getListVertex());
	auto& listNormals(model.getListNormals());
	//if (this->box.calculIntersection(rayon, scene, I, complexite)) {
	for (auto&& face : model.getListFaces()) {
		float dist = 0.f;
		glm::vec2 baryPos;
		glm::vec3 facteur(this->factor),
				pointA = facteur * listVertex.at(static_cast<unsigned long>(face.s1)) + this->center,
				pointB = facteur * listVertex.at(static_cast<unsigned long>(face.s2)) + this->center,
				pointC = facteur * listVertex.at(static_cast<unsigned long>(face.s3)) + this->center;
		if (glm::intersectRayTriangle(rayon.Orig(), rayon.Vect(), pointA, pointB, pointC, baryPos, dist)) {
			I.emplace_back(dist,
						   listNormals.at(static_cast<unsigned long>(face.s1)) * baryPos.x +
						   listNormals.at(static_cast<unsigned long>(face.s2)) * baryPos.y +
						   listNormals.at(static_cast<unsigned long>(face.s3)) * (1 - baryPos.x - baryPos.y),
						   this);
		}
	}
	return true;
	/*} else
		return false;//*/
}

Mesh::Mesh(Material* material, const std::string& name, const glm::vec3& center, unsigned int factor, float angle, const glm::vec3& axis)
		: Objet(material), model(name, angle, axis), center(center),
		  factor(factor) {
	this->boundingBox();
}

Mesh::Mesh(Material* material, std::string&& name, glm::vec3&& center, unsigned int factor, float angle, glm::vec3&& axis)
		: Objet(material), model(name, angle, axis), center(center),
		  factor(factor) {
	this->boundingBox();
}

Mesh& Mesh::operator=(Mesh&& mesh) noexcept {
	if (this != &mesh) {
		this->model = std::move(mesh.model);
		this->box = mesh.box;
		this->center = mesh.center;
		this->factor = mesh.factor;
		this->material = mesh.material;
		mesh.material = nullptr;
	}
	return *this;
}

void Mesh::boundingBox() {
	float xMin = std::numeric_limits<float>::max(), yMin = std::numeric_limits<float>::max(), zMin = std::numeric_limits<float>::max(),
			xMax = 0, yMax = 0, zMax = 0;
	auto& listVertex(this->model.getListVertex());
	auto& listFace(model.getListFaces());
	//Objectif : paralléliser la boucle. Problème : min max, concurrence en écriture.
#pragma omp parallel for reduction(min: xMin) reduction(min: yMin) reduction(min: zMin) reduction(max: xMax) reduction(max: yMax) reduction(max: zMax)
	for (std::size_t i = 0; i < listFace.size(); ++i) {
		const auto& vertexS1(listVertex.at(static_cast<unsigned long>(listFace.at(i).s1))),
				vertexS2(listVertex.at(static_cast<unsigned long>(listFace.at(i).s2))),
				vertexS3(listVertex.at(static_cast<unsigned long>(listFace.at(i).s3)));

		/*
		 * Trouver le xMin.
		 */
		if (std::isgreater(xMin, vertexS1.x))
			xMin = vertexS1.x;
		if (std::isgreater(xMin, vertexS2.x))
			xMin = vertexS2.x;
		if (std::isgreater(xMin, vertexS3.x))
			xMin = vertexS3.x;

		/*
		 * Trouver le yMin
		 */
		if (std::isgreater(yMin, vertexS1.y))
			yMin = vertexS1.y;
		if (std::isgreater(yMin, vertexS2.y))
			yMin = vertexS2.y;
		if (std::isgreater(yMin, vertexS3.y))
			yMin = vertexS3.y;

		/*
		 * Trouver le zMin
		 */
		if (std::isgreater(zMin, vertexS1.z))
			zMin = vertexS1.z;
		if (std::isgreater(zMin, vertexS2.z))
			zMin = vertexS2.z;
		if (std::isgreater(zMin, vertexS3.z))
			zMin = vertexS3.z;

		/*
		 * Trouver le xMax
		 */
		if (std::isless(xMax, vertexS1.x))
			xMax = vertexS1.x;
		if (std::isless(xMax, vertexS2.x))
			xMax = vertexS2.x;
		if (std::isless(xMax, vertexS3.x))
			xMax = vertexS3.x;

		/*
		 * Trouver le yMax
		 */
		if (std::isless(yMax, vertexS1.y))
			yMax = vertexS1.y;
		if (std::isless(yMax, vertexS2.y))
			yMax = vertexS2.y;
		if (std::isless(yMax, vertexS3.y))
			yMax = vertexS3.y;

		/*
		 * Trouver le zMax
		 */
		if (std::isless(zMax, vertexS1.z))
			zMax = vertexS1.z;
		if (std::isless(zMax, vertexS2.z))
			zMax = vertexS2.z;
		if (std::isless(zMax, vertexS3.z))
			zMax = vertexS3.z;
	}
	this->box = BoundingBox(xMin, yMin, zMin, xMax, yMax, zMax);
}

Mesh::~Mesh() {
	delete this->material;
}
