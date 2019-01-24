//
// Created by Florent on 13/01/2019.
//

#ifndef RAYTRACER_K_DNODE_H
#define RAYTRACER_K_DNODE_H


#include <bounding_box.h>
#include "k_dtree.h"

class KDnode {
private:
	friend class KDtree;

	///Vector containing all the points of the triangles.
	std::vector<glm::vec3*> points;
	KDnode* left = nullptr;
	KDnode* right = nullptr;
	KDnode* parent = nullptr;

	KDnode() = default;

	virtual ~KDnode();

	/*
	 * TODO : construire ce « putain » de nœud.
	 */
	/**
	 *
	 * @param vertex
	 * @param depth
	 * @return
	 */
	KDnode build(const std::vector<glm::vec3>& vertex, uint32_t depth);

	/**
	 * Move assignment operator.
	 * @param node
	 * @return
	 */
	KDnode& operator=(KDnode&& node) noexcept; //finished

	/**
	 * Deleted copy assignment operator. Maybe it will change in the future.
	 * @param node
	 * @return
	 */
	KDnode& operator=(const KDnode& node) = delete;

public:
	bool operator<(const KDnode& rhs) const;

	bool operator>(const KDnode& rhs) const;

	bool operator<=(const KDnode& rhs) const;

	bool operator>=(const KDnode& rhs) const;

};


#endif //RAYTRACER_K_DNODE_H
