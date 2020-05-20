#include "objet.h"
#include "Materials/material.h"
#include "Materials/phong.h"
#include "Materials/perlin.h"
#include "Materials/texture.h"

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

void from_json(const json &j, Objet &obj) {
	if (j.at("Material").get<std::string>() == "Phong") {
		obj.material = std::make_shared<Phong>();
		j.at("Phong").get_to(static_cast<Phong &>(*obj.material));
	} else
		throw std::runtime_error("No other material than Phong is handled at the moment.");
}