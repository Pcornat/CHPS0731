//
// Created by Florent on 13/01/2019.
//

#include "k_dnode.h"

KDnode::~KDnode() {
#ifndef NDEBUG
	std::cout << "Inside KDnode destructor.\n";
#endif
	delete left;
	delete right;
}

KDnode& KDnode::operator=(KDnode&& node) noexcept {
	if (this != &node) {
#ifndef NDEBUG
		std::cout << "Using KDnode move assignment operator\n";
#endif
		this->right = node.right;
		this->left = node.left;
		this->parent = node.parent;
		node.parent = node.left = node.right = nullptr;
		this->points = std::move(node.points);
		node.points.clear();
	}
	return *this;
}

bool KDnode::operator<(const KDnode& rhs) const {
	return points < rhs.points;
}

bool KDnode::operator>(const KDnode& rhs) const {
	return rhs < *this;
}

bool KDnode::operator<=(const KDnode& rhs) const {
	return !(rhs < *this);
}

bool KDnode::operator>=(const KDnode& rhs) const {
	return !(*this < rhs);
}
