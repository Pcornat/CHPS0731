#include "image.h"
#include "camera.h"
#include "objet.h"
#include "sphere.hpp"
#include "plan.hpp"
#include "phong.h"

int main() {
	const unsigned int h = 480;
	const unsigned int l = 640;
	Camera myCamera;
	Scene scene;
	Image myImage(h, l);
	Sphere sphere(0.5f, -0.2f, 4.0f, 1, new Phong(glm::vec3(0.1f, 0.2f, 0.1f), glm::vec3(0.6f, 0.0f, 0.0f), 128.0f, 0.5f));
	Plan background(1.0f, 1.0f, 1.0f, 0.0f, 0.0f, 5.0f, 0.0f, 0.0f, -5.0f);
	Plan rooftop(0.933f, 0.509f, 0.933f, 0.0f, 5.0f, 0.0f, 0.0f, -5.0f, -4.0f);
	Plan left (0.545f, 0.f, 0.545f, 5.0f, 0.0f, 0.0f, -5.0f, 0.0f, -3.5f);
	Plan right (0.733f, 0.039f, 0.117f, -5.0f, 0.0f, 0.0f, 5.0f, 0.0f, -3.5f);
	Plan floor (0.360f, 0.266f, 0.980f, 0.0f, -5.0f, 0.0f, 0.0f, 5.0f, -4.0f);
	Light light(1.0f, 3.0f, -1.0f, 1.0f, 1.0f, 1.0f);
	scene.addObjet(&sphere);
	scene.addObjet(&background);
	scene.addObjet(&rooftop);
	scene.addObjet(&left);
	scene.addObjet(&floor);
	scene.addObjet(&right);
	scene.addLight(&light);
	myCamera.Calculer_image(myImage, scene, 3);

	myImage.Save("out.png");

	return EXIT_SUCCESS;
}
