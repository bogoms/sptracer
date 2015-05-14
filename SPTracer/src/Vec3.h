#ifndef SPT_VEC3_H
#define SPT_VEC3_H

#include <array>

namespace SPTracer
{

	class Vec3
	{
	public:
		explicit Vec3();
		explicit Vec3(float x, float y, float z);

		void Normalize();
		float EuclideanNorm() const;
		Vec3 RotateFromTo(const Vec3& fromDirection, const Vec3& toDirection);
		Vec3 RotateFromTo(const Vec3& fromDirection, const Vec3& toDirection, const Vec3& rotationAxis);
		Vec3 RotateAboutAxis(const Vec3& rotationAxis, float cosTheta);

		static Vec3 FromPhiTheta(float phi, float cosTheta);
		static Vec3 CrossProduct(const Vec3& lhs, const Vec3& rhs);

		const float& operator[](size_t index) const;
		float& operator[](size_t index);

		friend Vec3 operator+(const Vec3& lhs, const Vec3& rhs);
		friend Vec3 operator+(const Vec3& lhs, const float& rhs);
		friend Vec3 operator+(const float& lhs, const Vec3& rhs);
		friend void operator+=(Vec3& lhs, const Vec3& rhs);
		friend void operator+=(Vec3& lhs, const float& rhs);

		friend Vec3 operator-(const Vec3& rhs);
		friend Vec3 operator-(const Vec3& lhs, const Vec3& rhs);
		friend Vec3 operator-(const Vec3& lhs, const float& rhs);
		friend Vec3 operator-(const float& lhs, const Vec3& rhs);
		friend void operator-=(Vec3& lhs, const Vec3& rhs);
		friend void operator-=(Vec3& lhs, const float& rhs);

		friend float operator*(const Vec3& lhs, const Vec3& rhs);
		friend Vec3 operator*(const Vec3& lhs, const float& rhs);
		friend Vec3 operator*(const float& lhs, const Vec3& rhs);
		friend void operator*=(Vec3& lhs, const float& rhs);

		friend Vec3 operator/(const Vec3& lhs, const float& rhs);
		friend void operator/=(Vec3& lhs, const float& rhs);

	private:
		std::array<float, 3> values_;
	};

}

#endif
