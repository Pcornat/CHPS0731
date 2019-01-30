//
// Created by Florent on 27/01/2019.
//

#ifndef RAYTRACER_TO_JSON_H
#define RAYTRACER_TO_JSON_H


#include <map>
#include <vector>
#include <Configuration/json.hpp>

class ToJson {
public:
	using json = nlohmann::basic_json<std::map, std::vector, std::string, bool, int64_t, uint64_t, float>;

	virtual ToJson::json toJson() const = 0;
};


#endif //RAYTRACER_TO_JSON_H
