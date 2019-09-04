//
// Created by kevin on 23/10/2018.
//

#ifndef PROJECT_PLAN_LIGHT_H
#define PROJECT_PLAN_LIGHT_H

#include "rayon.h"
#include "light.h"

class Plan_light : public Light {
protected:
	glm::vec3 rightDir;
	glm::vec3 depthDir;
	float sampleStep;
	float height;
	float width;

public:
	~Plan_light() override = default;

	Plan_light() = default;

	/**
	 *
	 * @param position
	 * @param couleur
	 * @param rightDir
	 * @param depthDir
	 * @param sampleStep
	 * @param type
	 */
	explicit Plan_light(glm::vec3 &&position, glm::vec3 &&couleur, glm::vec3 &&rightDir, glm::vec3 &&depthDir, float sampleStep, float height,
						float width);

	const glm::vec3 &getRightDir() const;

	void setRightDir(const glm::vec3 &rightDir);

	const glm::vec3 &getDepthDir() const;

	void setDepthDir(const glm::vec3 &depthDir);

	float getSampleStep() const;

	void setSampleStep(float sampleStep);

	float getHeight() const;

	void setHeight(float height);

	float getWidth() const;

	void setWidth(float width);

	/**
	 * Compute shadows, soft shadows here. The distributed method.
	 * \todo : change the method to the volume method.
	 * @param point
	 * @param I
	 * @param sc
	 * @param complexite
	 * @return
	 */
	[[nodiscard]] float computeShadow(const glm::vec3 &point, const Intersection &I, const Scene &sc, int complexite) const override;
};


#endif //PROJECT_PLAN_LIGHT_H
