//
// Created by Florent on 13/01/2019.
//

#ifndef RAYTRACER_K_DTREE_H
#define RAYTRACER_K_DTREE_H


#include "k_dnode.h"
#include <set>

class KDtree {
private:
	///This is the tree
	KDnode* tree{nullptr};

	float epsilon{std::numeric_limits<float>::epsilon()};
	bool constructed{false};


public:
	KDtree() = default;

	virtual ~KDtree();

	explicit KDtree(const std::vector<glm::vec3>& vertex, uint32_t depth);

	void build(const std::vector<glm::vec3>& vertex, uint32_t depth);

};

#endif //RAYTRACER_K_DTREE_H
