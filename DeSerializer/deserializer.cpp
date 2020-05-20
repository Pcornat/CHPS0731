#include "deserializer.h"
#include "Camera/scene.h"
#include "Lights/plan_light.h"
#include "Materials/phong.h"
#include "Objects/sphere.hpp"
#include "Objects/plan.hpp"

void from_json(const json &j, Scene &sc) {
	const std::size_t sphereSize = j["Objets"]["Sphere"].size(),
			plansSize = j["Objets"]["Plans"].size(),
			meshSize = j["Objets"]["Mesh"].size(),
			objects = sphereSize + plansSize + meshSize;
	sc.objets.reserve(objects);
	const std::size_t lights = j["Light"]["Plan_light"].size();
	sc.lights.reserve(lights);

	for (size_t i = 0; i < sphereSize; ++i) {
		sc.objets.emplace_back(new Sphere()); // best practice
		j.at("Objets").at("Sphere")[i].get_to(static_cast<Sphere &>(*sc.objets.back()));
	}

	for (size_t i = 0; i < plansSize; ++i) {
		sc.objets.emplace_back(new Plan()); // best practice
		j.at("Objets").at("Plan")[i].get_to(static_cast<Plan &>(*sc.objets.back()));
	}

	for (size_t i = 0; i < lights; ++i) {
		sc.lights.emplace_back(new Plan_light()); // best practice
		j.at("Light").at("Plan_light")[i].get_to(static_cast<Plan_light &>(*sc.lights.back()));
	}
}