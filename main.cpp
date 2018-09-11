#include "image.h"
#include "camera.h"
#include "objet.h"
#include "sphere.hpp"

int main() {
	const unsigned int h = 480;
	const unsigned int l = 640;

	Camera myCamera;
	Scene scene;
	Image myImage(h, l);
	Sphere sphere(0.5f, -0.2f, 0.4f, 1);
	scene.addObjet(&sphere);
	myCamera.Calculer_image(myImage, scene, 3);

	myImage.Save("out.png");

	return EXIT_SUCCESS;
}