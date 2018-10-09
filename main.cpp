#include "image.h"
#include "camera.h"
#include "objet.h"
#include "sphere.hpp"
#include "triangle.h"
#include "plan.hpp"
#include "phong.hpp"

int main() {
	const unsigned int h = 480 * 2;
	const unsigned int l = 640 * 2;
	Camera myCamera;
	Scene scene;
	Image myImage(h, l);
	Sphere sphere(new Phong(glm::vec3(0.1f, 0.2f, 0.1f), glm::vec3(0.6f, 0.0f, 0.0f), 128.0f, 0.2f), glm::vec3(-0.5f, -0.2f, 25.0f), 1);
	Sphere secSpher(new Phong(glm::vec3(0.15f, 0.4f, 0.10f), glm::vec3(0.592f, 0.0f, 0.592f), 128.0f, 0.5f), glm::vec3(2.5f, -1.7f, 25.0f), 1);
	//Triangle triangle(glm::vec3(0, 0, 0), glm::vec3(-0.7f, -2.0f, 100.0f), glm::vec3(-4.7f, -2.0f, 100.0f), glm::vec3(-2.7f, 3.0f, 100.0f));
	Plan background(new Phong(glm::vec3(0.0f, 0.4f, 0.0f), glm::vec3(0.592f, 0.0f, 0.592f), 128.0f, 0.0f), glm::vec3(0.0f, 0.0f, 150.0f),
					glm::vec3(0.0f, 0.0f, -1.0f));
	Plan rooftop(new Phong(glm::vec3(0.933f, 0.509f, 0.933f), glm::vec3(0.0f, 2.0f, 0.0f), 128.f, 0.5f), glm::vec3(0.0f, 10.0f, 0.0f),
				 glm::vec3(0.0f, -1.0f, 0.0f));
	Plan left(new Phong(glm::vec3(0.545f, 0.000f, 0.545f), glm::vec3(0.0f, 0.6f, 0.0f), 128.f, 0.5f), glm::vec3(10.0f, 0.0f, 0.0f),
			  glm::vec3(-1.0f, 0.0f, 0.0f));
	Plan right(new Phong(glm::vec3(0.733f, 0.000f, 0.117f), glm::vec3(0.0f, 0.6f, 0.0f), 128.0f, 1.0f), glm::vec3(-10.0f, 0.0f, 0.0f),
			   glm::vec3(1.0f, 0.0f, 0.0f));
	Plan floor(new Phong(glm::vec3(0.360f, 0.266f, 0.980f), glm::vec3(0.4f, 0.2f, 0.0f), 128.f, 0.5f), glm::vec3(0.0f, -10.0f, 0.0f),
			   glm::vec3(0.0f, 1.0f, 0.0f));
	Plan closedBox(new Phong(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(1.0f, 0.0f, 0.0f), 128.0f, 1.0f), glm::vec3(0.0f, 0.0f, -10.0f),
				   glm::vec3(0.0f, 0.0f, 1.0f));
	Light light(glm::vec3(1.0f, 4.0f, 4.0f), glm::vec3(1.0f, 1.0f, 1.0f));
	scene.addLight(&light);
	scene.addObjet(&sphere);
	//scene.addObjet(&secSpher);
	//scene.addObjet(&triangle);
	scene.addObjet(&rooftop);
	scene.addObjet(&left);
	scene.addObjet(&floor);
	scene.addObjet(&right);
	scene.addObjet(&closedBox);
	//Background should always be put at the end.
	scene.addObjet(&background);//When this line is here, IT WORKS, IT'S MAGIC (seriously, gimme an explanation T_T)
	myCamera.Calculer_image(myImage, scene, 4);

	myImage.Save("out.png");

	return EXIT_SUCCESS;
}
