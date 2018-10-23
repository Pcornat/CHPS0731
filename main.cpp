#include "image.h"
#include "camera.h"
#include "objet.h"
#include "sphere.hpp"
#include "triangle.h"
#include "plan.hpp"
#include "phong.hpp"
#include "plan_light.h"

int main() {
	const unsigned int h = 1080;
	const unsigned int l = 1920;
	Camera myCamera;
	Scene scene;
	Image myImage(h, l);
	Sphere sphere(new Phong(false, glm::highp_dvec3(0.1, 0.2, 0.1), glm::highp_dvec3(0.6, 0.0, 0.0), 128.0, 1.0),
				  glm::highp_dvec3(-2.5, -0.2, 80.0),
				  1);
	Sphere secSpher(
			new Phong(false, glm::highp_dvec3(0.2f, 0.0f, 0.0f), glm::highp_dvec3(0.0f, 0.5f, 0.392f), 128.0f, 0.3f),
			glm::highp_dvec3(2.5f, -1.7f, 75.0f), 1);
	/*Triangle triangle(new Phong(false, glm::highp_dvec3(0.2f, 0.2f, 0.0f), glm::highp_dvec3(1.0f, 1.0f, 1.0f), 128.0f, 0.25f),
					  glm::highp_dvec3(1.7f, -2.0f, 100.0f),
					  glm::highp_dvec3(-2.7f, -2.0f, 100.0f), glm::highp_dvec3(-0.7f, 3.0f, 100.0f));*/
	Plan background(new Phong(false, glm::highp_dvec3(0.f, 0.f, 0.f), glm::highp_dvec3(0.3f, 0.3f, 0.3f), 64.0f, 1.0f),
					glm::highp_dvec3(0.0f, 0.0f, 100.0f),
					glm::highp_dvec3(0.0f, 0.0f, -1.0f));
	Plan rooftop(new Phong(false, glm::highp_dvec3(0.2f, 0.2f, 0.0f), glm::highp_dvec3(0.5f, 0.0f, 0.5f), 128.f, 0.3f),
				 glm::highp_dvec3(0.0f, 10.0f, 0.0f),
				 glm::highp_dvec3(0.0f, -1.0f, 0.0f));
	Plan left(new Phong(false, glm::highp_dvec3(0.2f, 0.0f, 0.2f), glm::highp_dvec3(0.0f, 0.6f, 0.0f), 128.f, 0.25f),
			  glm::highp_dvec3(10.0f, 0.0f, 0.0f),
			  glm::highp_dvec3(-1.0f, 0.0f, 0.0f));
	Plan right(new Phong(false, glm::highp_dvec3(0.0f, 0.2f, 0.2f), glm::highp_dvec3(0.6f, 0.0f, 0.0f), 128.0f, 0.6f),
			   glm::highp_dvec3(-10.0f, 0.0f, 0.0f),
			   glm::highp_dvec3(1.0f, 0.0f, 0.0f));
	Plan floor(new Phong(false, glm::highp_dvec3(0.2f, 0.2f, 0.2f), glm::highp_dvec3(0.2f, 0.0f, 0.5f), 128.f, 0.f),
			   glm::highp_dvec3(0.0f, -10.0f, 0.0f),
			   glm::highp_dvec3(0.0f, 1.0f, 0.0f));
	Plan closedBox(
			new Phong(false, glm::highp_dvec3(0.0f, 0.0f, 0.0f), glm::highp_dvec3(0.3f, 0.3f, 0.3f), 128.0f, 0.8f),
			glm::highp_dvec3(0.0f, 0.0f, -10.0f),
			glm::highp_dvec3(0.0f, 0.0f, 1.0f));
	/*Light light1(glm::highp_dvec3(1.0f, 4.0f, 80.0f), glm::highp_dvec3(1.f, 1.f, 1.f));*/
	Plan_light light(glm::highp_dvec3(1.0f, 4.0f, 80.0f), glm::highp_dvec3(1.f, 1.f, 1.f), 20.f, 20.f);

	scene.addLight(&light);

	scene.addObjet(&sphere);
	scene.addObjet(&secSpher);
	//scene.addObjet(&triangle);
	scene.addObjet(&rooftop);
	scene.addObjet(&left);
	scene.addObjet(&floor);
	scene.addObjet(&right);
	scene.addObjet(&closedBox);
	scene.addObjet(&background);
	myCamera.Calculer_image(myImage, scene, 20);

	myImage.Save("out.png");

	return EXIT_SUCCESS;
}
