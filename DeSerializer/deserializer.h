#ifndef RAYTRACER_DESERIALIZER_H
#define RAYTRACER_DESERIALIZER_H


#include <unordered_set>
#include <Camera/scene.h>
#include <Configuration/json.hpp>

class Deserializer {
public:
	using json = nlohmann::basic_json<std::map, std::vector, std::string, bool, int64_t, uint64_t, float>;

	static const std::string section;

	static const std::unordered_set<std::string> types;

	static void build_scene(Scene &scene, const std::string &fileName = std::string("config.json"));
};


#endif //RAYTRACER_DESERIALIZER_H
