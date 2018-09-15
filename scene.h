#ifndef __Raytracer__scene__
#define __Raytracer__scene__

#include <vector>

class Objet;

class Light;

class Scene {
protected:
public:
	std::vector<Objet*> Objets;
	std::vector<Light*> Lights;

	Scene() = default;

	~Scene() = default;

	void addObjet(Objet* o);

	void addLight(Light* l);
};

#endif