#include "objet.h"
#include <Materials/material.h>
#include <Materials/phong.h>
#include <Materials/perlin.h>
#include <Materials/texture.h>

Objet::Objet(const Deserializer::json &json) {
	decltype(Deserializer::types)::const_iterator iterator;

	if ((iterator = Deserializer::types.find(json.at("Material").get<std::string>())) != std::end(Deserializer::types)) {
		if (*iterator == "Phong")
			this->material = std::make_shared<Phong>(json.at(*iterator));

		else if (*iterator == "Perlin")
			this->material = std::make_shared<Perlin>(json.at(*iterator));

		else if (*iterator == "Texture")
			this->material = std::make_shared<Texture>(json.at(*iterator));
	}
}

const std::shared_ptr<Material> &Objet::get_material() const {
	return material;
}

void Objet::set_material(Material *material) {
	Objet::material.reset(material);
}

Objet &Objet::operator=(const Objet &objet) {
	if (this != &objet) {
		this->material = objet.material;
	}
	return *this;
}

Objet &Objet::operator=(Objet &&objet) noexcept {
	if (this != &objet) {
		this->material = std::move(objet.material);
	}
	return *this;
}

Objet::Objet(Material *material) : material(material) {}
