#include "camera.h"
#include "image_glm.h"
#include <chrono>

void Camera::setHaut(const glm::vec3& h) {
	Camera::haut = h - (Camera::dir * (Camera::dir * h));
	if (glm::length(Camera::haut) != 0.0f)
		Camera::haut = glm::normalize(Camera::haut);
}

void Camera::Calculer_image(BaseImage* const im, Scene& sc, int complexite) const {
	glm::vec3 foyer; // Foyer optique de la camera
	glm::vec3 droite; // Vecteur partant sur la droite dans le plan de l'ecran
	float dx, dy; // dimension des macro-pixels
	//int x, y; // Position dans l'image du pixel en cours de calcul
	glm::vec3 hg; // Position du pixel au centre du premier macro-pixel de l'ecran (en haut a gauche)

	// On calcule la position du foyer de la camera
	foyer = Camera::centre - (Camera::dir * Camera::dist);

	//std::cout << "centre : " << haut.x << " " << haut.y <<" " << haut.z << std::endl; 
	// On calcule le vecteur unitaire "droite" du plan
	droite = glm::cross(Camera::dir, Camera::haut);


	// On calcule le deltaX et le deltaY
	dx = Camera::largeur / im->getLargeur();
	dy = Camera::hauteur / im->getHauteur();

	// On calcule la position du premier point de l'ecran que l'on calculera
	hg = Camera::centre + (droite * ((dx * 0.5f) - (Camera::largeur * 0.5f))) + (Camera::haut * ((Camera::hauteur * 0.5f) - (dy * 0.5f)));

	// Pour chaque pixel de l'image a calculer
	auto chrono = std::chrono::high_resolution_clock::now();//Lancement du chrono de calcul
#pragma omp parallel for collapse(2)
	for (std::size_t y = 0; y < im->getHauteur(); y++) {
		for (std::size_t x = 0; x < im->getLargeur(); x++) {
			//TODO : anti-aliasing
			// On calcule la position dans l'espace de ce point
			Rayon ray; // Rayon a lancer
			glm::vec3 res;
			glm::vec3 pt; // Position de l'intersection entre le rayon a lancer et l'ecran

			pt = hg + (droite * (dx * x)) - (Camera::haut * (dy * y));
			pt.x = pt.x - (dx * 0.5f);
			pt.y = pt.y - (dy * 0.5f);

			// On prépare le rayon qui part du foyer et qui passe par ce point
			ray.setOrigine(pt);
			ray.setVectDirection(glm::normalize(pt - foyer)); //Vecteur directeur du rayon.

			res = ray.lancer(sc, complexite);
			im->setPixel(static_cast<uint32_t>(x), static_cast<uint32_t>(y), glm::abs(res));
		}
		//std::cout << "Ligne " << y << std::endl;
	}
	double diff = std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - chrono).count();
	std::cout << "Calcul en : " << std::round(diff / 60.0) << "m" << static_cast<unsigned int>(std::round(diff)) % 60 << "s" << std::endl;
}