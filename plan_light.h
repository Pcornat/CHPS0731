//
// Created by kevin on 23/10/2018.
//

#ifndef PROJECT_PLAN_LIGHT_H
#define PROJECT_PLAN_LIGHT_H

#include "light.h"

class Plan_light : public Light {
protected:
	float height;
	float width;
	float sampleStep;

public:
	virtual ~Plan_light();

	Plan_light() = default;

	explicit Plan_light(glm::highp_dvec3 &&position, glm::highp_dvec3 &&couleur, float height, float width,
						float sampleStep, unsigned short type);

	void setHeight(float height);

	void setWidth(float width);

	unsigned short getType() const;

	void setType(unsigned short type);

	float getSampleStep() const;

	float getHeight() const;

	float getWidth() const;

	void setSampleStep(float sampleStep);
};


#endif //PROJECT_PLAN_LIGHT_H
