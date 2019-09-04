#include "material.h"

Material::Material(const Deserializer::json &json) : refraction(json.at("refraction").get<bool>()) {
}
