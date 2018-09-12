//
// Created by kevin on 12/09/18.
//

#ifndef CHPS0731_PHONG_H
#define CHPS0731_PHONG_H


#include "material.h"
#include "light.h"

/**
 * \class Phong
 * This class is a material,it define the texture, the representation of an object.
 */

class Phong : public Material {
private:
    glm::vec3 Ka;
    glm::vec3 Kd;
    glm::vec3 Amb;
    glm::vec3 Dif;
    float Spec;
    float Ks;

public:
    Phong() = default;

    Phong(glm::vec3, glm::vec3, float);

    Phong(glm::vec3, glm::vec3, glm::vec3, glm::vec3, float, float);

    void Ambiant(Light &light);

    void Diffuse();



};


#endif //CHPS0731_PHONG_H
