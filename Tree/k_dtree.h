//
// Created by Florent on 13/01/2019.
//

#ifndef RAYTRACER_K_DTREE_H
#define RAYTRACER_K_DTREE_H


#include <set>
#include <glm/vec3.hpp>
#include <vector>
#include <Objects/Mesh/GeometricModel.h>
#include "kd_tree_iterator.h"

/**
 * @todo écrire un itérateur. Write an iterator.
 * @class KDtree
 */
class KDtree {
private:
	friend KDTreeIterator;

	class KDnode;

	///This is the tree
	KDnode* tree{nullptr};

	///The model from the kd-tree is built.
	GeometricModel* model{nullptr};

	float epsilon{std::numeric_limits<float>::epsilon()};

	bool constructed{false};

public:
	KDtree() = default;

	virtual ~KDtree();

	explicit KDtree(GeometricModel* model, uint32_t depth);

	void build();

	const std::string& treeFrom() const;

	bool operator==(const KDtree& kDtree);
};

#endif //RAYTRACER_K_DTREE_H
