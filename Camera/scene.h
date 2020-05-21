#ifndef __Raytracer__scene__
#define __Raytracer__scene__

#include <vector>
#include <memory>
#include "Lights/light.h"
#include "Objects/objet.h"

class Scene {
public:
	std::vector<std::unique_ptr<const Objet>> objets;

	std::vector<std::unique_ptr<const Light>> lights;

	Scene() = default;

	Scene(const Scene &scene) = delete;

	Scene(Scene &&sc) noexcept: objets(std::move(sc.objets)), lights(std::move(sc.lights)) {}

	virtual ~Scene() noexcept = default;

	auto operator=(const Scene &sc) -> Scene & = delete;

	auto operator=(Scene &&sc) noexcept -> Scene & {
		if (this != &sc) {
			this->lights = std::move(sc.lights);
			this->objets = std::move(sc.objets);
		}
		return *this;
	}

	[[gnu::always_inline, nodiscard]] inline const std::vector<std::unique_ptr<const Objet>> &getObjets() const {
		return Scene::objets;
	}

	[[gnu::always_inline, nodiscard]] inline const std::vector<std::unique_ptr<const Light>> &getLights() const {
		return Scene::lights;
	}

};

#endif