//
// Created by Florent on 25/01/2019.
//

#ifndef RAYTRACER_CONFIGURATION_H
#define RAYTRACER_CONFIGURATION_H


#include <string>
#include <ostream>
#include <map>
#include <vector>
#include <Objects/objet.h>
#include <to_json.h>

/**
 * @class Configuration
 * @brief It is a singleton class for the configuration file for the program.
 */
class Configuration {
private:
	using json = ToJson::json;

	std::string fileName = "config.json";

	json file;

	static bool alreadyCreated;

	void init();

public:
	Configuration();

	virtual ~Configuration() noexcept;

	explicit Configuration(const std::string& fileName);

	explicit Configuration(std::string&& fileName);

	friend std::ostream& operator<<(std::ostream& os, const Configuration& configuration);

	friend Configuration& operator>>(const Objet& obj, Configuration& conf);

};


#endif //RAYTRACER_CONFIGURATION_H
