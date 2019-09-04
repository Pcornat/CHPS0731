//
// Created by Florent on 15/12/2018.
//

#ifndef PROJECT_BASE_IMAGE_H
#define PROJECT_BASE_IMAGE_H

#include <string>

#define GLM_FORCE_INLINE
#define GLM_FORCE_XYZW_ONLY

#include <glm/vec3.hpp>

class BaseImage {
protected:
	///It is the height of the picture
	uint32_t hauteur;

	///It is the width of the picture
	uint32_t largeur;

public:
	BaseImage() = default;

	explicit BaseImage(uint32_t hauteur, uint32_t largeur);

	virtual ~BaseImage() = default;

	virtual void setPixel(std::uint32_t x, std::uint32_t y, const glm::vec3 &pixel) = 0;

	virtual bool save(const std::string &name) = 0;

	/**
	 *
	 * @return
	 */
	uint32_t getHauteur() const;

	/**
	 *
	 * @return
	 */
	uint32_t getLargeur() const;
};


#endif //PROJECT_BASE_IMAGE_H
