#include "image.h"
#include "camera.h"
#include "objet.h"
#include "sphere.hpp"
#include "phong.h"

int main() {
	const unsigned int h = 480;
	const unsigned int l = 640;
//	const unsigned int h = 720;
//	const unsigned int l = 1280;
	Camera myCamera;
	Scene scene;
	Image myImage(h, l);
	//Sphere sphere(0.5f, -0.2f, 4.0f, 1, 1.0f, 1.0f, 1.0f);
	Sphere sphere(0.5f, -0.2f, 4.0f, 1, new Phong(glm::vec3(0.1f, 0.2f, 0.1f), glm::vec3(0.6f, 0.0f, 0.0f), 128.0f));
	Light light(1.0f, 3.0f, -1.0f);
	scene.addObjet(&sphere);
	scene.addLight(&light);
	myCamera.Calculer_image(myImage, scene, 3);

	myImage.Save("out.png");

	return EXIT_SUCCESS;
}
