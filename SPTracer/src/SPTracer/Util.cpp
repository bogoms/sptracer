#include "stdafx.h"
#include "Util.h"

namespace SPTracer
{

	const float Util::Eps = 1e-5f;
	const float Util::Pi = 3.14159265358979323846f;

	int Util::RandInt(int min, int max)
	{
		static unsigned int count = 1000;
		static thread_local std::mt19937 generator(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) + ++count);
		std::uniform_int_distribution<int> distribution(min, max);
		return distribution(generator);
	}

	float Util::RandFloat(float min, float max)
	{
		static unsigned int count = 0;
		static thread_local std::mt19937 generator(static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count()) + ++count);
		std::uniform_real_distribution<float> distribution(min, max);
		return distribution(generator);
	}

}
