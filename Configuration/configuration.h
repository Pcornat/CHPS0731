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
#include <from_json.h>

/**
 * @class Configuration
 * @brief It is a singleton class for the configuration file for the program.
 */
class Configuration {
private:
	///@sa ToJson::json
	using json = FromJson::json;

	///@brief the name of file to read and write from.
	std::string fileName = "config.json";

	///@brief The Json object that will be used to read or write.
	json file;

	static bool alreadyCreated;

	/**
	 * This private method is used in all the constructors to make this class a singleton. It is not optimised at all.
	 */
	void init();

public:
	/**
	 *
	 */
	Configuration();

	/**
	 *
	 */
	virtual ~Configuration() noexcept;

	/**
	 *
	 * @param fileName
	 */
	explicit Configuration(const std::string& fileName);

	/**
	 *
	 * @param fileName
	 */
	explicit Configuration(std::string&& fileName);

	/**
	 *
	 * @param os
	 * @param configuration
	 * @return
	 */
	friend std::ostream& operator<<(std::ostream& os, const Configuration& configuration);

};


#endif //RAYTRACER_CONFIGURATION_H
