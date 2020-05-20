#ifndef __Raytracer__scene__
#define __Raytracer__scene__

#include <vector>
#include <memory>
#include "Lights/light.h"
#include "Objects/objet.h"

class Scene {
public:
	std::vector<std::unique_ptr<Objet>> objets;

	std::vector<std::unique_ptr<Light>> lights;

	Scene() = default;

	virtual ~Scene() noexcept = default;

	void addObjet(Objet *o);

	void addLight(Light *l);

	[[gnu::always_inline, nodiscard]] inline const std::vector<std::unique_ptr<Objet>> &getObjets() const {
		return Scene::objets;
	}

	[[gnu::always_inline, nodiscard]] inline const std::vector<std::unique_ptr<Light>> &getLights() const {
		return Scene::lights;
	}

};

#endif