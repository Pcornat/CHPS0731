#include "mesh.h"
#include "triangle.h"

bool Mesh::calculIntersection(const Rayon& rayon, const Scene& scene, std::vector<Intersection>& I, int complexite) {
	bool intersect = false;
	auto& listVertex(model.getListVertex());
	if (this->box.calculIntersection(rayon, scene, I, complexite)) {
		for (auto&& face : model.getListFaces()) {
			Triangle triangle;
			try {
				glm::vec3 facteur(this->factor);
				triangle = Triangle(nullptr, facteur * listVertex.at(static_cast<unsigned long>(face.s1)) + this->center,
									facteur * listVertex.at(static_cast<unsigned long>(face.s2)) + this->center,
									facteur * listVertex.at(static_cast<unsigned long>(face.s3)) + this->center);
			} catch (const std::exception& e) {
				std::cerr << e.what() << std::endl;
				exit(EXIT_FAILURE);
			}
			if ((intersect = triangle.calculIntersection(rayon, scene, I, complexite))) {
				glm::vec3 s1s2(listVertex.at(static_cast<unsigned long>(face.s2)) - listVertex.at(static_cast<unsigned long>(face.s1)));
				glm::vec3 s1s3(listVertex.at(static_cast<unsigned long>(face.s3)) - listVertex.at(static_cast<unsigned long>(face.s1)));
				I.at(I.size() - 1).setNormal(glm::cross(s1s2, s1s3));
				I.at(I.size() - 1).setObj(this);
			}
		}
		return true;
	} else
		return false;
}

Mesh::Mesh(Material* material, const std::string& name, const glm::vec3& center, unsigned int factor) : Objet(material), model(name), center(center),
																										factor(factor) {
	this->boundingBox();
}

Mesh::Mesh(Material* material, std::string&& name, glm::vec3&& center, unsigned int factor) : Objet(material), model(name), center(center),
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
	//Objectif : paralléliser la boucle. Problème : min max, concurrence en écriture.
	for (auto face = model.getListFaces().begin(); face != model.getListFaces().end(); ++face) {
		const auto& vertexS1(listVertex.at(static_cast<unsigned long>(face->s1))),
				vertexS2(listVertex.at(static_cast<unsigned long>(face->s2))),
				vertexS3(listVertex.at(static_cast<unsigned long>(face->s3)));

		/*
		 * Trouver le xMin.
		 */
		if (xMin > vertexS1.x)
			xMin = vertexS1.x;
		if (xMin > vertexS2.x)
			xMin = vertexS2.x;
		if (xMin > vertexS3.x)
			xMin = vertexS3.x;

		/*
		 * Trouver le yMin
		 */
		if (yMin > vertexS1.y)
			yMin = vertexS1.y;
		if (yMin > vertexS2.y)
			yMin = vertexS2.y;
		if (yMin > vertexS3.y)
			yMin = vertexS3.y;

		/*
		 * Trouver le zMin
		 */
		if (zMin > vertexS1.z)
			zMin = vertexS1.z;
		if (zMin > vertexS2.z)
			zMin = vertexS2.z;
		if (zMin > vertexS3.z)
			zMin = vertexS3.z;

		/*
		 * Trouver le xMax
		 */
		if (xMax < vertexS1.x)
			xMax = vertexS1.x;
		if (xMax < vertexS2.x)
			xMax = vertexS2.x;
		if (xMax < vertexS3.x)
			xMax = vertexS3.x;

		/*
		 * Trouver le yMax
		 */
		if (yMax < vertexS1.y)
			yMax = vertexS1.y;
		if (yMax < vertexS2.y)
			yMax = vertexS2.y;
		if (yMax < vertexS3.y)
			yMax = vertexS3.y;

		/*
		 * Trouver le zMax
		 */
		if (zMax < vertexS1.z)
			zMax = vertexS1.z;
		if (zMax < vertexS2.z)
			zMax = vertexS2.z;
		if (zMax < vertexS3.z)
			zMax = vertexS3.z;
	}
	this->box = BoundingBox(xMin, yMin, zMin, xMax, yMax, zMax);
}

Mesh::~Mesh() {
	delete this->material;
}
