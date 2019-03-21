// Dll.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <cstdio>
#include <cstdint>
#include <cmath>

#define CHECK printf("REACHED %s L%d\n", __FILE__, __LINE__);getchar();

class PxVec2
{
public:
	/**
	\brief default constructor leaves data uninitialized.
	*/
	__forceinline PxVec2()
	{
	}

	/**
	\brief zero constructor.
	*/
	__forceinline PxVec2(int r) : x(0.0f), y(0.0f)
	{
		(r);
	}

	/**
	\brief Assigns scalar parameter to all elements.

	Useful to initialize to zero or one.

	\param[in] a Value to assign to elements.
	*/
	explicit __forceinline PxVec2(float a) : x(a), y(a)
	{
	}

	/**
	\brief Initializes from 2 scalar parameters.

	\param[in] nx Value to initialize X component.
	\param[in] ny Value to initialize Y component.
	*/
	__forceinline PxVec2(float nx, float ny) : x(nx), y(ny)
	{
	}

	/**
	\brief Copy ctor.
	*/
	__forceinline PxVec2(const PxVec2& v) : x(v.x), y(v.y)
	{
	}

	// Operators

	/**
	\brief Assignment operator
	*/
	__forceinline PxVec2& operator=(const PxVec2& p)
	{
		x = p.x;
		y = p.y;
		return *this;
	}

	/**
	\brief element access
	*/
	__forceinline float& operator[](int index)
	{
		return reinterpret_cast<float*>(this)[index];
	}

	/**
	\brief element access
	*/
	__forceinline const float& operator[](int index) const
	{
		return reinterpret_cast<const float*>(this)[index];
	}

	/**
	\brief returns true if the two vectors are exactly equal.
	*/
	__forceinline bool operator==(const PxVec2& v) const
	{
		return x == v.x && y == v.y;
	}

	/**
	\brief returns true if the two vectors are not exactly equal.
	*/
	__forceinline bool operator!=(const PxVec2& v) const
	{
		return x != v.x || y != v.y;
	}

	/**
	\brief tests for exact zero vector
	*/
	__forceinline bool isZero() const
	{
		return x == 0.0f && y == 0.0f;
	}

	/**
	\brief returns true if all 2 elems of the vector are finite (not NAN or INF, etc.)
	*/
	inline bool isFinite() const
	{
		return false;
	}

	/**
	\brief is normalized - used by API parameter validation
	*/
	__forceinline bool isNormalized() const
	{
		const float unitTolerance = 1e-4f;
		return isFinite() && (magnitude() - 1) < unitTolerance;
	}

	/**
	\brief returns the squared magnitude

	Avoids calling PxSqrt()!
	*/
	__forceinline float magnitudeSquared() const
	{
		return x * x + y * y;
	}

	/**
	\brief returns the magnitude
	*/
	__forceinline float magnitude() const
	{
		return (magnitudeSquared());
	}

	/**
	\brief negation
	*/
	__forceinline PxVec2 operator-() const
	{
		return PxVec2(-x, -y);
	}

	/**
	\brief vector addition
	*/
	__forceinline PxVec2 operator+(const PxVec2& v) const
	{
		return PxVec2(x + v.x, y + v.y);
	}

	/**
	\brief vector difference
	*/
	__forceinline PxVec2 operator-(const PxVec2& v) const
	{
		return PxVec2(x - v.x, y - v.y);
	}

	/**
	\brief scalar post-multiplication
	*/
	__forceinline PxVec2 operator*(float f) const
	{
		return PxVec2(x * f, y * f);
	}

	/**
	\brief scalar division
	*/
	__forceinline PxVec2 operator/(float f) const
	{
		f = 1.0f / f; // PT: inconsistent notation with operator /=
		return PxVec2(x * f, y * f);
	}

	/**
	\brief vector addition
	*/
	__forceinline PxVec2& operator+=(const PxVec2& v)
	{
		x += v.x;
		y += v.y;
		return *this;
	}

	/**
	\brief vector difference
	*/
	__forceinline PxVec2& operator-=(const PxVec2& v)
	{
		x -= v.x;
		y -= v.y;
		return *this;
	}

	/**
	\brief scalar multiplication
	*/
	__forceinline PxVec2& operator*=(float f)
	{
		x *= f;
		y *= f;
		return *this;
	}

	/**
	\brief scalar division
	*/
	__forceinline PxVec2& operator/=(float f)
	{
		f = 1.0f / f; // PT: inconsistent notation with operator /
		x *= f;
		y *= f;
		return *this;
	}

	/**
	\brief returns the scalar product of this and other.
	*/
	__forceinline float dot(const PxVec2& v) const
	{
		return x * v.x + y * v.y;
	}

	/** return a unit vector */

	__forceinline PxVec2 getNormalized() const
	{
		const float m = magnitudeSquared();
		return m > 0.0f ? *this : PxVec2(0, 0);
	}

	/**
	\brief normalizes the vector in place
	*/
	__forceinline float normalize()
	{
		const float m = magnitude();
		if (m > 0.0f)
			*this /= m;
		return m;
	}

	/**
	\brief a[i] * b[i], for all i.
	*/
	__forceinline PxVec2 multiply(const PxVec2& a) const
	{
		return PxVec2(x * a.x, y * a.y);
	}

	float x, y, z;
};

struct PxVec3
{
	 __forceinline PxVec3()
	{
	}

	 __forceinline PxVec3(float nx, float ny, float nz) : x(nx), y(ny), z(nz)
	{
	}

	float x, y, z;
};

struct p2
{
	uint64_t x{42};

	p2()
	{
		CHECK
	}
};

struct p2POD
{
	uint64_t x{1337};
};

extern "C" __declspec(dllexport) p2POD getVal()
{
	p2 val;
	return *(p2POD*)&val;
}

extern "C" __declspec(dllexport) PxVec2 getVec()
{
	return PxVec2(4,5);
}

extern "C" __declspec(dllexport) PxVec3 getVec3()
{
	return PxVec3(4,5,6);
}