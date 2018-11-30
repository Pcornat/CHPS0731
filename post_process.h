//
// Created by Florent on 20/11/2018.
//

#ifndef PROJECT_POST_PROCESS_H
#define PROJECT_POST_PROCESS_H

#include <glm/glm.hpp>
#include <vector>

class PostProcess {
public:
	static void TONE_MAPPING_UCHIMURA_PHONG(glm::vec3& input);

	static void TONE_MAPPING_LOTTES_PHONG(glm::vec3& input);

	static void TONE_MAPPING_SIMPLE_IMAGE(std::vector<glm::vec3>& pixels, const std::size_t& hauteur, const std::size_t& largeur);

};


#endif //PROJECT_POST_PROCESS_H
