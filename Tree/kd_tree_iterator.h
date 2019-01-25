//
// Created by Florent on 25/01/2019.
//

#ifndef RAYTRACER_KD_TREE_ITERATOR_H
#define RAYTRACER_KD_TREE_ITERATOR_H


#include <iterator>
#include "k_dnode.h"

class KDTreeIterator : public std::iterator<std::bidirectional_iterator_tag, KDnode> {
private:
	friend KDtree;

	KDtree& myTree;
	pointer currentNode{nullptr};
	pointer lastNode{nullptr};

public:
	KDTreeIterator() = default;

};


#endif //RAYTRACER_KD_TREE_ITERATOR_H
