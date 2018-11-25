//
// Created by Florent on 20/11/2018.
//

#include "post_process.h"

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

void PostProcess::TONE_MAPPING_SIMPLE_IMAGE(std::vector<glm::vec3>& pixels) {
	glm::vec3 seuilHaut, seuilBas;
	float xMin = std::numeric_limits<float>::max(),
			xMax = 0,
			yMin = std::numeric_limits<float>::max(),
			yMax = 0,
			zMin = std::numeric_limits<float>::max(),
			zMax = 0;
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
#pragma omp parallel for reduction(min: xMin) reduction(min: yMin) reduction(min: zMin)\
        reduction(max: xMax) reduction(max: yMax) reduction(max: zMax)
	for (std::size_t i = 0; i < pixels.size(); ++i) {
		auto& var = pixels.at(i);

		//So beautiful <3
		xMin = min(var.x, xMin);
		yMin = min(var.y, yMin);
		zMin = min(var.z, zMin);

		xMax = max(var.x, xMax);
		yMax = max(var.y, yMax);
		zMax = max(var.z, zMax);
	}
	seuilBas = glm::vec3(xMin, yMin, zMin), seuilHaut = glm::vec3(xMax, yMax, zMax);
}
