//
// Created by Florent on 20/11/2018.
//

#include "post_process.h"
#include <unordered_map>

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/gtx/color_space.hpp>

void PostProcess::TONE_MAPPING_UCHIMURA_PHONG(glm::vec3& input) {
	const float P = 1.0f,
			a = 1.7f,
			invA = 1 / a,
			m = 0.1f,
			l = 0.2f,
			c = 1.33f,
			b = 0.0f;
	const float l0 = ((P - m) * l) * invA;
	const float L0 = m - m * invA;
	const float L1 = m + (1.0f - m) * invA;
	const float S0 = m + l0;
	const float S1 = m + a * l0;
	const float C2 = a / (P - S1); //a * P but P = 1.0f
	const float CP = -C2; //-C2 / P but P = 1.0f

	const float w0 = 1.0f - glm::smoothstep(0.0f, m, input.x);
	const float w2 = glm::step(m + l0, input.x);
	const float w1 = 1.0f - w0 - w2;

	const float T = m * glm::pow(input.x / m, c) + b;
	const float S = P - (P - S1) * glm::exp(CP * (input.x - S0));
	const float L = m + a * (input.x - m);

	const float toneMapping = T * w0 + L * w1 + S * w2;
}

void PostProcess::TONE_MAPPING_LOTTES_PHONG(glm::vec3& input) {
	// Lottes 2016, "Advanced Techniques and Optimization of HDR Color Pipelines"
	const float a = 1.6;
	const float d = 0.977;
	const float hdrMax = 8.0;
	const float midIn = 0.18;
	const float midOut = 0.267;

	// Can be precomputed
	const float b =
			(-glm::pow(midIn, a) + glm::pow(hdrMax, a) * midOut) /
			((glm::pow(hdrMax, a * d) - glm::pow(midIn, a * d)) * midOut);
	const float c =
			(glm::pow(hdrMax, a * d) * glm::pow(midIn, a) - glm::pow(hdrMax, a) * glm::pow(midIn, a * d) * midOut) /
			((glm::pow(hdrMax, a * d) - glm::pow(midIn, a * d)) * midOut);
	const float toneMapping = glm::pow(input.x, a) / (glm::pow(input.x, a * d) * b + c);


}

void PostProcess::TONE_MAPPING_SIMPLE_IMAGE(std::vector<glm::vec3>& pixels, const std::size_t& hauteur, const std::size_t& largeur) {
	std::vector<float> histoCum(largeur * hauteur);
	float minV = std::numeric_limits<float>::max(), maxV = 0.f;
	//Lambda function to code faster.
	auto min = [](float a, float b) {
		if (std::isless(a, b))
			return a;
		else
			return b;
	};
	auto max = [](float a, float b) {
		if (std::isgreater(a, b))
			return a;
		else
			return b;
	};

#pragma omp parallel for collapse(2) reduction(min: minV) reduction(max: maxV)
	for (unsigned y = 0; y < hauteur; ++y) {
		for (unsigned x = 0; x < largeur; ++x) {
			auto& pixel(pixels.at(x + largeur * y));
			pixel.r = pixel.x;
			pixel.g = pixel.y;
			pixel.b = pixel.z;

			pixel = glm::hsvColor(pixel);
			histoCum.at(x + largeur * y) = pixel.z;
			minV = min(minV, pixel.z);
			maxV = max(maxV, pixel.z);
		}
	}
	float alpha = (1.f / (maxV - minV));
	float beta = (-minV) * alpha;
	//Normalisation de l'image
#pragma omp parallel for collapse(2)
	for (unsigned y = 0; y < hauteur; ++y) {
		for (unsigned x = 0; x < largeur; ++x) {
			auto& pixel = pixels.at(x + largeur * y);
			pixel.z = alpha * pixel.z + beta;
			histoCum.at(x + largeur * y) += histoCum.at((x + largeur * y) - 1);//Normalement, histogramme cumulé
		}
	}

	float ratio = 1.0f / (hauteur * largeur);
	//Égalisation de l'histogramme
#pragma omp parallel for collapse(2)
	for (unsigned y = 0; y < hauteur; ++y) {
		for (unsigned x = 0; x < largeur; ++x) {
			auto& pixel(pixels.at(x + largeur * y));
			pixel.z = histoCum.at(x + largeur * y) * ratio;

			//Nouvelles valeurs, théoriquement
			pixel = glm::rgbColor(pixel);
			if (std::isgreater(pixel.r, 1.0f)) {
				pixel.r /= 255.f;
			}
			if (std::isgreater(pixel.g, 1.0f)) {
				pixel.g /= 255.f;
			}
			if (std::isgreater(pixel.g, 1.0f)) {
				pixel.g /= 255.f;
			}
			pixel.x = pixel.r;
			pixel.y = pixel.g;
			pixel.z = pixel.b;
		}
	}
}
