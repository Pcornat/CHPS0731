#include "mesh.h"

bool Mesh::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int complexite) {
	auto& listVertex(model->getListVertex());
	auto& listNormals(model->getListNormals());
	bool inter = false;
	//if (this->box.calculIntersection(rayon, scene, I, complexite)) {
	for (auto&& face : model->getListFaces()) {
		float dist = 0.f;
		glm::vec2 baryPos;
		glm::vec3 facteur(this->factor),
				pointA = facteur * listVertex.at(static_cast<unsigned long>(face.s1)) + this->center,
				pointB = facteur * listVertex.at(static_cast<unsigned long>(face.s2)) + this->center,
				pointC = facteur * listVertex.at(static_cast<unsigned long>(face.s3)) + this->center;
		if ((inter = glm::intersectRayTriangle(rayon.Orig(), rayon.Vect(), pointA, pointB, pointC, baryPos, dist)) && std::isgreater(dist, 0.f)) {
			I.emplace_back(dist,
						   listNormals.at(static_cast<unsigned long>(face.s2)) * baryPos.x +
						   listNormals.at(static_cast<unsigned long>(face.s3)) * baryPos.y +
						   listNormals.at(static_cast<unsigned long>(face.s1)) * (1 - baryPos.x - baryPos.y),
						   this);
		}
	}
	return inter;
	/*} else
		return false;//*/
}

Mesh::Mesh(Material* material, const std::string& name, const glm::vec3& center, unsigned int factor, float angle, const glm::vec3& axis)
		: Objet(material), model(new GeometricModel(name, angle, axis)), center(center), factor(factor) {
	this->boundingBox();
}

Mesh::Mesh(Material* material, std::string&& name, glm::vec3&& center, unsigned int factor, float angle, glm::vec3&& axis)
		: Objet(material), model(new GeometricModel(name, angle, axis)), center(center), factor(factor) {
	this->boundingBox();
}

Mesh::Mesh(Material* material, glm::vec3&& center, uint32_t factor, float angle, glm::vec3&& axis)
		: Objet(material), model(nullptr), center(center), factor(factor) {}

Mesh::Mesh(Material* material, const glm::vec3& center, uint32_t factor, float angle, const glm::vec3& axis)
		: Objet(material), model(nullptr), center(center), factor(factor) {}

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
	auto& listVertex(this->model->getListVertex());
	auto& listFace(model->getListFaces());
	//Lambda function to code faster.
	auto min = [](float a, float b) {
		if (std::isless(a, b))
			return a;
		else
			return b;
	};
	auto max = [](float a, float b) {
		if (std::isgreater(a, b))
			return a;
		else
			return b;
	};

#pragma omp parallel for reduction(min: xMin) reduction(min: yMin) reduction(min: zMin) reduction(max: xMax) reduction(max: yMax) reduction(max: zMax)
	for (std::size_t i = 0; i < listFace.size(); ++i) {
		const auto& vertexS1(listVertex.at(static_cast<unsigned long>(listFace.at(i).s1))),
				vertexS2(listVertex.at(static_cast<unsigned long>(listFace.at(i).s2))),
				vertexS3(listVertex.at(static_cast<unsigned long>(listFace.at(i).s3)));

		/*
		 * Trouver le xMin.
		 */
		xMin = min(xMin, vertexS1.x);
		xMin = min(xMin, vertexS2.x);
		xMin = min(xMin, vertexS3.x);

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

Mesh::~Mesh() {
	delete this->material;
}

const glm::vec3& Mesh::getCenter() const {
	return center;
}

void Mesh::setCenter(const glm::vec3& center) {
	Mesh::center = center;
}

unsigned int Mesh::getFactor() const {
	return factor;
}

void Mesh::setFactor(unsigned int factor) {
	Mesh::factor = factor;
}

void Mesh::setModel(const Mesh& model) {
	if (this != &model) {
		Mesh::model = model.model->shared_from_this();
		this->boundingBox();
	}
}