#ifndef __Raytracer__image__
#define __Raytracer__image__

#include "base_image.h"
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include <vector>

class ImageGLM : public BaseImage {
protected:
	std::vector<glm::vec3> pixels;

public:
	ImageGLM(uint32_t height, uint32_t largeur);

	ImageGLM(std::string &&name);

	~ImageGLM() override = default;

	bool save(const std::string &name) override;

	void setPixel(uint32_t x, uint32_t y, const glm::vec3 &pixel) override;
};

#endif