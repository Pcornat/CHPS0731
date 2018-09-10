
#include "image.h"
#include "camera.h"
#include "objet.h"


int main(int argc, char* argv[]) {
	const int h = 480;
	const int l = 640;

	Camera myCamera;
	Scene scene;
	Image myImage = *new Image(h, l);

	myCamera.Calculer_image(myImage, scene, 3);

	myImage.Save("out.png");

	return 0;
}