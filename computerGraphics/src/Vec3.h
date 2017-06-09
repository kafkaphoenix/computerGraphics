/*
 * Vec3.h
 *
 *  Created on: 9 jun. 2017
 *      Author: sorak
 */

#ifndef VEC3_H_
#define VEC3_H_

template <typename T>
class Vec3
{
public:
	Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
	Vec3(const T &xx) : x(xx), y(xx), z(xx) {}
	Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}

	T length();
	T dot(const Vec3<T> &v) const
	{
			return x * v.x + y * v.y + z * v.z;
	}
	Vec3<T>& normalize()
	{
		T len2 = dot(*this);
		if(len2 > 0)
		{
			T invLen = 1 / sqrt(len2);
			x *= invLen;
			y *= invLen;
			z *= invLen;
		}

		return *this;
	}
	Vec3<T> operator + (const Vec3<T> &v) const
	{
		return Vec3<T>(x + v.x, y + v.y, z + v.z);
	}
	Vec3<T> operator - (const Vec3<T> &v) const
	{
		return Vec3<T>(x - v.x, y - v.y, z - v.z);
	}
	Vec3<T> operator * (const T &r) const
	{
		return Vec3<T>(x * r, y * r, z * r);
	}

	T x, y, z;
};

template <typename T>
T length(const Vec3<T> &v)
{
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
}

template <typename T>
void normalize(Vec3<T> &v)
{
	T len2 = v.x * v.x + v.y * v.y + v.z * v.z;
	if(len2 > 0)
	{
		T invLen = 1 / sqrt(len2);
		v.x *= invLen;
		v.y *= invLen;
		v.z *= invLen;
	}
}

template <typename T>
T dot(const Vec3<T> &a, const Vec3<T> &b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

template <typename T>
 Vec3<T> cross(const Vec3<T> &a, const Vec3<T> &b)
 {
	return Vec3<T>(
		a.y * b.z - a.z * b.y,
		b.z * a.x - b.x * a.z,
		a.x * b.y - a.y * b.x);
 }

#endif /* VEC3_H_ */
