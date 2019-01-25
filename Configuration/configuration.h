//
// Created by Florent on 25/01/2019.
//

#ifndef RAYTRACER_CONFIGURATION_H
#define RAYTRACER_CONFIGURATION_H


#include <string>
#include <json.hpp>
#include <ostream>

class Configuration {
private:
	using json = nlohmann::basic_json<std::map, std::vector, std::string, bool, int64_t, uint64_t, float>;

	std::string fileName = "config.json";

	json file;

	//Après bah jsp lel on verra.

public:
	Configuration() = default;

	virtual ~Configuration() noexcept = default;

	explicit Configuration(const std::string& fileName);

	explicit Configuration(std::string&& fileName);

	friend std::ostream& operator<<(std::ostream& os, const Configuration& configuration);

};


#endif //RAYTRACER_CONFIGURATION_H
