#include "image.h"
#include "camera.h"
#include "objet.h"


int main(int argc, char* argv[]) {
	const unsigned int h = 480;
	const unsigned int l = 640;

	Camera myCamera;
	Scene scene;
	Image myImage(h, l);

	myCamera.Calculer_image(myImage, scene, 3);

	myImage.Save("out.png");

	return 0;
}