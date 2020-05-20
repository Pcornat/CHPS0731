#ifndef RAYTRACER_DESERIALIZER_H
#define RAYTRACER_DESERIALIZER_H

#include <unordered_set>

#define GLM_FORCE_INLINE
#define GLM_FORCE_XYZW_ONLY

#include <glm/vec3.hpp>

#include "Configuration/json.hpp"

class Scene;

using json = nlohmann::basic_json<std::map, std::vector, std::string, bool, int64_t, uint64_t, float>;

namespace nlohmann {
	template<>
	struct adl_serializer<glm::vec3> {
		static void from_json(const json &j, glm::vec3 &vec) {
			vec.x = j[0].get<float>();
			vec.y = j[1].get<float>();
			vec.z = j[2].get<float>();
		}

		static void to_json(json &j, const glm::vec3 &vec) {
			j[0] = vec.x;
			j[1] = vec.y;
			j[2] = vec.z;
		}
	};
}

void from_json(const json &j, Scene &sc);


#endif //RAYTRACER_DESERIALIZER_H
