//
// Created by kevin on 23/10/2018.
//

#ifndef PROJECT_PLAN_LIGHT_H
#define PROJECT_PLAN_LIGHT_H

#include "light.h"
#include "rayon.h"

class Plan_light : public Light {
protected:
	glm::vec3 height;
	glm::vec3 width;
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
	explicit Plan_light(glm::vec3&& position, glm::vec3&& couleur, glm::vec3&& height, glm::vec3&& width, float sampleStep);

	const glm::vec3& getHeight() const;

	void setHeight(const glm::vec3& height);

	const glm::vec3& getWidth() const;

	void setWidth(const glm::vec3& width);

	float getSampleStep() const;

	void setSampleStep(float sampleStep);

	/**
	 * Compute shadows, soft shadows here. The distributed method.
	 * \todo : change the method to the volume method.
	 * @param point
	 * @param I
	 * @param sc
	 * @param complexite
	 * @return
	 */
	float computeShadow(const glm::vec3& point, const Intersection& I, const Scene& sc, int complexite) override;
};


#endif //PROJECT_PLAN_LIGHT_H
