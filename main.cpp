#include <Materials/phong.h>
#include <image.h>
#include <camera.h>
#include <objet.h>
#include <sphere.hpp>
#include <plan.hpp>
#include <plan_light.h>
#include <mesh.h>
#include <iomanip>

int main(int argc, char* argv[]) {
	const unsigned int h = 480;
	const unsigned int l = 640;
	Camera myCamera;
	Scene scene;
	Image myImage(h, l);
	std::stringstream ss;
	std::time_t time;//*/
	Mesh mesh;
	if (argc != 2) {
		std::cerr << "Nombre d'arguments insuffisant, nom d'un fichier .obj attendu." << std::endl;
		return EXIT_FAILURE;
	}
	try {
		mesh = Mesh(new Phong(false, glm::vec3(0.2f, 0.3f, 0.2f), glm::vec3(0.6f, 0.f, 0.3f), 128.0f, 0.0f),
					std::string(argv[1]),
					glm::vec3(0.f, -3.9f, 8.f), 15, 180.f, glm::vec3(0, 1, 0));
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}//*/

	Sphere sphere(new Phong(false, glm::vec3(0.2f, 0.3f, 0.2f), glm::vec3(0.6f, 0.0f, 0.0f), 128.0f, 1.0f),
				  glm::vec3(-2.5f, -4.0f, 10.0f), 1);
	Sphere secSpher(new Phong(false, glm::vec3(0.2f, 0.0f, 0.0f), glm::vec3(0.0f, 0.5f, 0.392f), 128.0f, 0.5f),
					glm::vec3(2.5f, -1.7f, 5.0f), 1);
	Plan background(new Phong(false, glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.3f, 0.3f, 0.3f), 128.0f, 1.0f),
					glm::vec3(0.0f, 0.0f, 20.0f),
					glm::vec3(0.0f, 0.0f, -1.0f));
	Plan rooftop(new Phong(false, glm::vec3(0.2f, 0.2f, 0.0f), glm::vec3(0.5f, 0.0f, 0.5f), 128.f, 0.0f),
				 glm::vec3(0.0f, 10.0f, 0.0f),
				 glm::vec3(0.0f, -1.0f, 0.0f));
	Plan left(new Phong(false, glm::vec3(0.2f, 0.0f, 0.2f), glm::vec3(0.0f, 0.6f, 0.0f), 128.f, 0.5f),
			  glm::vec3(10.0f, 0.0f, 0.0f),
			  glm::vec3(-1.0f, 0.0f, 0.0f));
	Plan right(new Phong(false, glm::vec3(0.0f, 0.2f, 0.2f), glm::vec3(0.6f, 0.0f, 0.0f), 128.0f, 0.5f),
			   glm::vec3(-10.0f, 0.0f, 0.0f),
			   glm::vec3(1.0f, 0.0f, 0.0f));
	Plan floor(new Phong(false, glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.2f, 0.0f, 0.5f), 128.f, 0.f),
			   glm::vec3(0.0f, -5.0f, 0.0f),
			   glm::vec3(0.0f, 1.0f, 0.0f));
	Plan closedBox(
			new Phong(false, glm::vec3(0.3f, 0.2f, 0.2f), glm::vec3(0.3f, 0.3f, 0.3f), 128.0f, 0.25f),
			glm::vec3(0.0f, 0.0f, -10.0f),
			glm::vec3(0.0f, 0.0f, 1.0f));
	Plan_light light(glm::vec3(-7.0f, 8.0f, -5.0f), glm::vec3(1.0f, 1.0f, 1.0f),
					 glm::vec3(1.0f, 0.f, 0.f),
					 glm::vec3(0.f, 0.0f, 1.0f),
					 0.5000000000f, 2.f, 2.f);
	Plan_light light2(glm::vec3(7.0f, 8.0f, -5.0f), glm::vec3(1.0f, 1.0f, 1.0f),
					  glm::vec3(1.0f, 0.f, 0.f),
					  glm::vec3(0.f, 0.0f, 1.0f),
					  0.5000000000f, 2.f, 2.f);
	scene.addLight(&light);
	scene.addLight(&light2);

	scene.addObjet(&sphere);
	scene.addObjet(&secSpher);
	scene.addObjet(&rooftop);
	scene.addObjet(&left);
	scene.addObjet(&floor);
	scene.addObjet(&right);
	scene.addObjet(&closedBox);
	scene.addObjet(&background);
	scene.addObjet(&mesh);

	try {
		myCamera.Calculer_image(myImage, scene, 6);
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	std::time(&time);
	ss << "out_" << std::put_time(std::localtime(&time), "%d_%m_%Y_%Hh%Mm%Ss") << ".png";
	try {
		myImage.Save(ss.str());
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
//*/
	//myImage.Save("out.png");
	return EXIT_SUCCESS;
}
