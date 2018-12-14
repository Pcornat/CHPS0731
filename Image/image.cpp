#include <post_process.h>
#include "image.h"
#include "png/lodepng.h"

void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
	//Encode the image
	unsigned error = lodepng::encode(filename, image, width, height);

	//if there's an error, display it
	if (error) std::cerr << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

Image::Image(const unsigned int h, const unsigned int l) : pixels(l * h), hauteur(h), largeur(l) {}


void Image::save(const std::string& name) {
	std::cout << "Saving:" << name << "..." << std::endl;
	std::size_t width = Image::largeur, height = Image::hauteur;
	std::vector<unsigned char> image;
	image.resize(width * height * 4);
	/* TODO : TONE MAPPING HERE */
	//PostProcess::TONE_MAPPING_SIMPLE_IMAGE(Image::pixels);
#pragma omp parallel for collapse(2)
	for (unsigned y = 0; y < height; ++y)
		for (unsigned x = 0; x < width; ++x) {
			glm::vec3 tmp = Image::pixels.at(x + Image::largeur * y);
			tmp.x = glm::max(glm::min(1.0f, tmp.x), 0.0f);
			tmp.y = glm::max(glm::min(1.0f, tmp.y), 0.0f);
			tmp.z = glm::max(glm::min(1.0f, tmp.z), 0.0f);
			image.at(4 * width * y + 4 * x + 0) = static_cast<unsigned char>(std::round(tmp.x * 255.0f));
			image.at(4 * width * y + 4 * x + 1) = static_cast<unsigned char>(std::round(tmp.y * 255.0f));
			image.at(4 * width * y + 4 * x + 2) = static_cast<unsigned char>(std::round(tmp.z * 255.0f));
			image.at(4 * width * y + 4 * x + 3) = 255;
		}
	encodeOneStep(name.c_str(), image, static_cast<unsigned int>(width), static_cast<unsigned int>(height));
	std::cout << "Done!" << std::endl;
}


Image::Image(std::string&& name) {

	std::vector<unsigned char> image; //the raw pixels
	unsigned width, height;
	std::cout << "Loading:" << name << std::endl;
	unsigned error = lodepng::decode(image, width, height, name);

	//if there's an error, display it
	if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
	Image::hauteur = height;
	Image::largeur = width;
	Image::pixels.resize(this->hauteur * this->largeur);
#pragma omp parallel for collapse(2)
	for (unsigned y = 0; y < height; y++)
		for (unsigned x = 0; x < width; x++) {
			Image::pixels[x + Image::largeur * y] = glm::vec3(image[4 * width * y + 4 * x + 0] / 255.0f,
															  image[4 * width * y + 4 * x + 1] / 255.0f,
															  image[4 * width * y + 4 * x + 2] / 255.0f);
		}
}

size_t Image::getHauteur() const {
	return hauteur;
}

size_t Image::getLargeur() const {
	return largeur;
}

void Image::setPixel(int x, int y, const glm::vec3& c) {
	Image::pixels.at(x + Image::largeur * y) = c;
}