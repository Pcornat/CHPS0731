//
// Created by Florent on 13/01/2019.
//

#ifndef RAYTRACER_K_DTREE_H
#define RAYTRACER_K_DTREE_H


#include <set>
#include <glm/vec3.hpp>
#include <vector>
#include <Objects/Mesh/GeometricModel.h>

class KDtree {
private:
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

};

#endif //RAYTRACER_K_DTREE_H
