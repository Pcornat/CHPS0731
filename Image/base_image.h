//
// Created by Florent on 15/12/2018.
//

#ifndef PROJECT_BASE_IMAGE_H
#define PROJECT_BASE_IMAGE_H

#include <string>
#include <glm/vec3.hpp>
#include <Effects/effect.h>

class BaseImage {
protected:

	///It is the vector of effects to apply to the picture put in the right order.
	std::vector<Effect*> effects;

	///It is the height of the picture
	uint32_t hauteur;

	///It is the width of the picture
	uint32_t largeur;

public:
	BaseImage() = default;

	explicit BaseImage(uint32_t hauteur, uint32_t largeur);

	explicit BaseImage(const std::vector<Effect*>& effects, uint32_t hauteur, uint32_t largeur);

	explicit BaseImage(std::initializer_list<Effect*> effects, uint32_t hauteur, uint32_t largeur);

	virtual ~BaseImage() = default;

	virtual void setPixel(std::uint32_t x, std::uint32_t y, const glm::vec3& pixel) = 0;

	virtual bool save(const std::string& name) = 0;

	/**
	 * To know the height of the picture
	 * @return
	 */
	uint32_t getHauteur() const;

	/**
	 * To know the width of the picture
	 * @return
	 */
	uint32_t getLargeur() const;

	/**
	 * You can have the vector of Effects.
	 * @return
	 */
	const std::vector<Effect*>& getEffects() const;

	/**
	 * You can add an effect.
	 * @param effect
	 */
	void addEffect(Effect* effect);
};


#endif //PROJECT_BASE_IMAGE_H
