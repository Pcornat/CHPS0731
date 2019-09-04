#include "deserializer.h"
#include <filesystem>
#include <Objects/sphere.hpp>

const std::string Deserializer::section{ "Objects" };

const std::unordered_set<std::string> Deserializer::types{ "Sphere", "Plan", "Mesh", "PlanLight", "Phong", "Perlin", "Texture" };

void Deserializer::build_scene(Scene &scene, const std::string &fileName) {
	const size_t pos = fileName.find(".json");

	if (pos == std::string::npos)
		throw std::invalid_argument("No file extension found or wrong extension");

	if (!std::filesystem::exists(fileName))
		throw std::invalid_argument("File does not exist.");

	const json fileJson(fileName);
	{
		const auto &objSect = fileJson.at(section);
		for (const auto &obj : objSect) {
			decltype(types)::const_iterator iterator;
			if ((iterator = types.find(obj.at("type").get<std::string>())) != std::end(types)) {
				if (*iterator == "Sphere") {
					scene.addObjet(new Sphere(obj));
				}
			} else {
				std::stringstream excptMsg("Exception at ");
				excptMsg << __LINE__ << " in " << __FILE__ << '\n'
						 << "No field named \"type\" is in the json file.\n";
				throw std::logic_error(excptMsg.str());
			}
		}
	}
}
