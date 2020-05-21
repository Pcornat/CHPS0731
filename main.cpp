#include <iostream>
#include <iomanip>
#include <Camera/camera.h>
#include <Camera/scene.h>
#include <Lights/plan_light.h>
#include <Objects/Mesh/mesh.h>
#include <Materials/phong.h>
#include <Image/image_cv.h>
#include <fstream>

int main(int argc, char *argv[]) {
	constexpr uint32_t h = 1080;
	constexpr uint32_t l = 1920;
	const Camera myCamera;
	ImageCV myImage(h, l);
	Mesh stanfordBunny_1, bunny2(new Phong(false, glm::vec3(0.2f, 0.3f, 0.2f), glm::vec3(0.6f, 0.f, 0.3f), 128.0f, 0.0f),
								 glm::vec3(0.f, -3.8f, 8.f), 15, 180.f, glm::vec3(0, 1, 0));
	if (argc < 2) {
		std::cerr << "Nombre d'arguments insuffisant, nom d'un fichier .obj attendu." << std::endl;
		return EXIT_FAILURE;
	}
	try {
		stanfordBunny_1 = Mesh(new Phong(false, glm::vec3(0.2f, 0.3f, 0.2f), glm::vec3(0.6f, 0.f, 0.3f), 128.0f, 0.0f),
							   std::string(argv[1]),
							   glm::vec3(0.f, -3.8f, 8.f), 15, 180.f, glm::vec3(0, 1, 0));
	} catch (const std::exception &e) {
		std::cerr << "Bunny : " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	bunny2.setModel(stanfordBunny_1);

/*	const Sphere sphere(new Phong(false, glm::vec3(0.2f, 0.3f, 0.2f), glm::vec3(0.6f, 0.0f, 0.0f), 128.0f, 1.0f),
						glm::vec3(-2.5f, -4.0f, 10.0f), 1);
	const Sphere secSpher(new Phong(false, glm::vec3(0.2f, 0.0f, 0.0f), glm::vec3(0.0f, 0.5f, 0.392f), 128.0f, 0.5f),
						  glm::vec3(2.5f, -1.7f, 5.0f), 1);
	const Plan background(new Phong(false, glm::vec3(0.f, 0.f, 0.f), glm::vec3(0.3f, 0.3f, 0.3f), 128.0f, 1.0f),
						  glm::vec3(0.0f, 0.0f, 20.0f),
						  glm::vec3(0.0f, 0.0f, -1.0f));
	const Plan rooftop(new Phong(false, glm::vec3(0.2f, 0.2f, 0.0f), glm::vec3(0.5f, 0.0f, 0.5f), 128.f, 0.0f),
					   glm::vec3(0.0f, 10.0f, 0.0f),
					   glm::vec3(0.0f, -1.0f, 0.0f));
	const Plan left(new Phong(false, glm::vec3(0.2f, 0.0f, 0.2f), glm::vec3(0.0f, 0.6f, 0.0f), 128.f, 0.5f),
					glm::vec3(10.0f, 0.0f, 0.0f),
					glm::vec3(-1.0f, 0.0f, 0.0f));
	const Plan right(new Phong(false, glm::vec3(0.0f, 0.2f, 0.2f), glm::vec3(0.6f, 0.0f, 0.0f), 128.0f, 0.5f),
					 glm::vec3(-10.0f, 0.0f, 0.0f),
					 glm::vec3(1.0f, 0.0f, 0.0f));
	const Plan floor(new Phong(false, glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.2f, 0.0f, 0.5f), 128.f, 0.f),
					 glm::vec3(0.0f, -5.0f, 0.0f),
					 glm::vec3(0.0f, 1.0f, 0.0f));
	const Plan closedBox(
			new Phong(false, glm::vec3(0.3f, 0.2f, 0.2f), glm::vec3(0.3f, 0.3f, 0.3f), 128.0f, 0.25f),
			glm::vec3(0.0f, 0.0f, -10.0f),
			glm::vec3(0.0f, 0.0f, 1.0f));
	const Plan_light light(glm::vec3(-7.0f, 9.0f, -5.0f), glm::vec3(1.0f, 1.0f, 1.0f),
						   glm::vec3(1.0f, 0.f, 0.f),
						   glm::vec3(0.f, 0.0f, 1.0f),
						   0.2000000000f, 2.f, 2.f);
	scene.lights.emplace_back(&light);

	scene.objets.emplace_back(&sphere);
	scene.objets.emplace_back(&secSpher);
	scene.objets.emplace_back(&rooftop);
	scene.objets.emplace_back(&left);
	scene.objets.emplace_back(&floor);
	scene.objets.emplace_back(&right);
	scene.objets.emplace_back(&closedBox);
	scene.objets.emplace_back(&background);*/
//	scene.objets.emplace_back(&stanfordBunny_1);
//	scene.objets.emplace_back(&bunny2);

	json j;
	{
		std::ifstream file("config.json");
		j = json::parse(file);
	}
	const auto scene = j.at("Scene").get<Scene>();

	try {
		myCamera.Calculer_image(&myImage, scene, 6);
	} catch (const std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	{
		std::time_t time = 0;
		std::time(&time);
		std::stringstream ss;
		ss << "out_" << std::put_time(std::localtime(&time), "%Y_%m_%d_%Hh%Mm%Ss") << ".png";
		try {

			myImage.save(ss.str());

		} catch (const std::exception &e) {
			std::cerr << "Exception writing : " << e.what() << std::endl;
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;
}
