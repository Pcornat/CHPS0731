#ifndef __Raytracer__scene__
#define __Raytracer__scene__

#include <vector>

class Objet;

class Light;

class Scene {
protected:
	std::vector<Objet *> Objets;

	std::vector<Light *> Lights;

public:
	Scene() = default;

	virtual ~Scene() noexcept;

	void addObjet(Objet *o);

	void addLight(Light *l);

	[[gnu::always_inline, nodiscard]] inline const std::vector<Objet *> &getObjets() const {
		return Scene::Objets;
	}

	[[gnu::always_inline, nodiscard]] inline const std::vector<Light *> &getLights() const {
		return Scene::Lights;
	}

};

#endif