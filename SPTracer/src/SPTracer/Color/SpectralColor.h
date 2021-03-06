#ifndef SPT_SPECTRAL_COLOR_H
#define SPT_SPECTRAL_COLOR_H

#include "../stdafx.h"
#include "Color.h"

namespace SPTracer
{

	class SpectralColor : public Color
	{
	public:
		struct Amplitude
		{
			float waveLength;	// length
			float amplitude;	// amplitude
		};

		explicit SpectralColor(std::vector<Amplitude> amplitudes);
		virtual float GetAmplitude(float waveLength) const override;

	private:
		std::vector<Amplitude> amplitudes_;
	};

}

#endif
