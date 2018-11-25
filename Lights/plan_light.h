//
// Created by kevin on 23/10/2018.
//

#ifndef PROJECT_PLAN_LIGHT_H
#define PROJECT_PLAN_LIGHT_H

#include "light.h"
#include "rayon.h"

class Plan_light : public Light {
protected:
	float height;
	float width;
	float sampleStep;

public:
	~Plan_light() override = default;

	Plan_light() = default;

	/**
	 *
	 * @param position
	 * @param couleur
	 * @param height
	 * @param width
	 * @param sampleStep
	 * @param type
	 */
	explicit Plan_light(glm::vec3&& position, glm::vec3&& couleur, float height, float width, float sampleStep);

	void setHeight(float height);

	void setWidth(float width);

	float getSampleStep() const;

	float getHeight() const;

	float getWidth() const;

	void setSampleStep(float sampleStep);

	float computeShadow(const glm::vec3& point, const Intersection& I, const Scene& sc, int complexite) override;
};


#endif //PROJECT_PLAN_LIGHT_H
