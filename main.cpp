#include "image.h"
#include "camera.h"
#include "objet.h"
#include "sphere.hpp"
#include "plan.hpp"
#include "phong.hpp"
#include "mesh.h"

int main(int argc, char* argv[]) {
	const unsigned int h = 1080;
	const unsigned int l = 1920;
	Camera myCamera;
	Scene scene;
	Image myImage(h, l);
	Mesh mesh;
	if (argc != 2) {
		std::cerr << "Nombre d'arguments insuffisant." << std::endl;
		exit(EXIT_FAILURE);
	}
	try {
		mesh = Mesh(new Phong(false, glm::vec3(0.1f, 0.2f, 0.1f), glm::vec3(0.6f, 0.f, 0.3f), 128.0f, 0.0f), std::string(argv[1]),
					glm::vec3(0.f, 0.f, 100.f), 15, 180.f, glm::vec3(0, 1, 0));
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		exit(EXIT_FAILURE);
	}//*/

	Sphere sphere(new Phong(false, glm::vec3(0.1, 0.2, 0.1), glm::vec3(0.6, 0.0, 0.0), 128.0, 0.0),
				  glm::vec3(-2.5, -0.2, 100.0), 1);
	Sphere secSpher(new Phong(false, glm::vec3(0.2f, 0.0f, 0.0f), glm::vec3(0.0f, 0.5f, 0.392f), 128.0f, 0.0f),
					glm::vec3(2.5f, -1.7f, 100.0f), 1);
	/*Triangle triangle(new Phong(false, glm::vec3(0.2f, 0.2f, 0.0f), glm::vec3(0.4f, 0.3f, 0.3f), 128.0f, 0.25f),
					  glm::vec3(1.7f, -2.0f, 100.0f),
					  glm::vec3(-2.7f, -2.0f, 100.0f), glm::vec3(-0.7f, 3.0f, 100.0f));*/
	Plan background(new Phong(false, glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.3f, 0.3f, 0.3f), 128.0f, 0.0f),
					glm::vec3(0.0f, 0.0f, 200.0f),
					glm::vec3(0.0f, 0.0f, -1.0f));
	Plan rooftop(new Phong(false, glm::vec3(0.2f, 0.2f, 0.0f), glm::vec3(0.5f, 0.0f, 0.5f), 128.f, 0.0f),
				 glm::vec3(0.0f, 10.0f, 0.0f),
				 glm::vec3(0.0f, -1.0f, 0.0f));
	Plan left(new Phong(false, glm::vec3(0.2f, 0.0f, 0.2f), glm::vec3(0.0f, 0.6f, 0.0f), 128.f, 0.0f),
			  glm::vec3(10.0f, 0.0f, 0.0f),
			  glm::vec3(-1.0f, 0.0f, 0.0f));
	Plan right(new Phong(false, glm::vec3(0.0f, 0.2f, 0.2f), glm::vec3(0.6f, 0.0f, 0.0f), 128.0f, 0.0f),
			   glm::vec3(-10.0f, 0.0f, 0.0f),
			   glm::vec3(1.0f, 0.0f, 0.0f));
	Plan floor(new Phong(false, glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.2f, 0.0f, 0.5f), 128.f, 0.f),
			   glm::vec3(0.0f, -10.0f, 0.0f),
			   glm::vec3(0.0f, 1.0f, 0.0f));
	Plan closedBox(
			new Phong(false, glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.3f, 0.3f, 0.3f), 128.0f, 1.0f),
			glm::vec3(0.0f, 0.0f, -10.0f),
			glm::vec3(0.0f, 0.0f, 0.0f));
	Light light(glm::vec3(1.0f, 4.0f, 4.0f), glm::vec3(1.0f, 1.0f, 1.0f));
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
	scene.addObjet(&mesh);
	myCamera.Calculer_image(myImage, scene, 6);

	myImage.Save("out.png");

	return EXIT_SUCCESS;
}
