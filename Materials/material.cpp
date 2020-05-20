#include "material.h"

Material::Material(const json &json) : refraction(json.at("refraction").get<bool>()) {
}
