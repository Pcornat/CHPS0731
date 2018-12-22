//
// Created by Florent on 22/12/2018.
//

#ifndef RAYTRACER_EFFECT_H
#define RAYTRACER_EFFECT_H


class Effect {
public:

	Effect() = default;

	virtual ~Effect() = default;

	virtual bool effect(void* args) = 0;
};


#endif //RAYTRACER_EFFECT_H
