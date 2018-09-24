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
	Sphere sphere(new Phong(glm::vec3(0.1f, 0.2f, 0.1f), glm::vec3(0.6f, 0.0f, 0.0f), 128.0f, 0.5f), glm::vec3(0.5f, -0.2f, 4.0f), 1);
	Plan background(glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 0.0f, 150.0f), glm::vec3(0.0f, 0.0f, -1.0f));
	Plan rooftop(glm::vec3(0.933f, 0.509f, 0.933f), glm::vec3(0.0f, 10.0f, 0.0f), glm::vec3(0.0f, -1.0f, 0.0f));
	Plan left(glm::vec3(0.545f, 0.000f, 0.545f), glm::vec3(10.0f, 0.0f, 0.0f), glm::vec3(-1.0f, 0.0f, 0.0f));
	Plan right(glm::vec3(0.733f, 0.039f, 0.117f), glm::vec3(-10.0f, 0.0f, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	Plan floor(glm::vec3(0.360f, 0.266f, 0.980f), glm::vec3(0.0f, -10.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
	Plan closedBox(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.0f, 0.0f, -10.0f), glm::vec3(0.0f, 0.0f, 1.0f));
	Light light(glm::vec3(1.0f, 3.0f, -1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	scene.addLight(&light);
	scene.addObjet(&sphere);
	scene.addObjet(&rooftop);
	scene.addObjet(&left);
	scene.addObjet(&floor);
	scene.addObjet(&right);
	scene.addObjet(&closedBox);
	//Background should always be put at the end.
	scene.addObjet(&background);//When this line is here, IT WORKS, IT'S MAGIC (seriously, gimme an explanation T-T)
	myCamera.Calculer_image(myImage, scene, 3);

	myImage.Save("out.png");

	return EXIT_SUCCESS;
}
