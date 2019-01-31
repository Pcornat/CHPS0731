//
// Created by Florent on 27/01/2019.
//

#ifndef RAYTRACER_TO_JSON_H
#define RAYTRACER_TO_JSON_H


#include <map>
#include <vector>
#include <Configuration/json.hpp>

/**
 * @class ToJson to_json.h to_json
 * @brief This is the interface to use for the configuration class
 * @sa Configuration
 */
class FromJson {
public:
	///Personnal type : the only difference is the real type : float instead of double
	using json = nlohmann::basic_json<std::map, std::vector, std::string, bool, int64_t, uint64_t, float>;

	/**
	 * Pure virtual member function.
	 * @return a json object.
	 */
	virtual void fromJson(const FromJson::json& objet) const = 0;
};


#endif //RAYTRACER_TO_JSON_H
