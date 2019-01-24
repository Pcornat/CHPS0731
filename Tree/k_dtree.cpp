//
// Created by Florent on 13/01/2019.
//

#include "k_dtree.h"

KDtree::~KDtree() {

}

KDtree::KDtree(GeometricModel* const model, uint32_t depth) : model(model), constructed(true) {

}

void KDtree::build() {
	if (constructed)
		return;


	constructed = true;
}

const std::string& KDtree::treeFrom() const {
	return model->getName();
}
