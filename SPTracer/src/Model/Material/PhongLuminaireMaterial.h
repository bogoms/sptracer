#ifndef SPT_PHONG_LUMINAIRE_MATERIAL_H
#define SPT_PHONG_LUMINAIRE_MATERIAL_H

#include <memory>
#include "Material.h"

namespace SPTracer
{

	class Color;

	class PhongLuminaireMaterial : public Material
	{
	public:
		PhongLuminaireMaterial(
			std::unique_ptr<Material> reflectiveMaterial,
			std::unique_ptr<Color> radiantExitance,
			float phongExponent,
			const Spectrum& spectrum);

		bool IsEmissive() const override;
		void GetDiffuseReflectance(const Ray& ray, const Intersection& intersection, const Ray& newRay, std::vector<float>& reflectance) const override;
		void GetSpecularReflectance(const Ray& ray, const Intersection& intersection, const Ray& newRay, std::vector<float>& reflectance) const override;
		float GetSpecularExponent() const;
		void GetRadiance(const Ray& ray, const Intersection& intersection, std::vector<float>& radiance) const override;
		float GetDiffuseReflectionProbability(int waveIndex) const override;		// use index -1 for average reflectivity
		float GetSpecularReflectionProbability(int waveIndex) const override;		// use index -1 for average reflectivity

	private:
		std::unique_ptr<Material> reflectiveMaterial_;
		std::unique_ptr<Color> radiantExitance_;
		float phongExponent_;
		std::vector<float> precomputedRadiance_;
	};

}

#endif
