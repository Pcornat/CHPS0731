//
// Created by Florent on 13/01/2019.
//

#include "k_dtree.h"

KDtree::~KDtree() {

}

KDtree::KDtree(const std::vector<glm::vec3>& vertex, uint32_t depth) : constructed(true) {

}

void KDtree::build(const std::vector<glm::vec3>& vertex, uint32_t depth) {
	if (constructed)
		return;


	constructed = true;
}
