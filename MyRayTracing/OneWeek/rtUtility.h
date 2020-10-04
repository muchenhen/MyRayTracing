/*
记录数学常量
*/
#pragma once
#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <random>
#include <iostream>
#include "Ray.h"

using point3 = Eigen::Vector3d;
using color3 = Eigen::Vector3d;

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();//无穷大
const double PI = 3.14159265;//圆周率

inline double DegreesToRadians(double degress)
{
	return degress * PI / 180.0;
}

inline double RandomDouble()
{
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);
	static std::mt19937 generator;
	return distribution(generator);
}

inline double RandomDouble(double min, double max)
{
	return min + (max - min) * RandomDouble();
}

inline vec3 Random()
{
	return vec3(RandomDouble(), RandomDouble(), RandomDouble());
}

inline vec3 Random(double min, double max)
{
	return vec3(RandomDouble(min, max), RandomDouble(min, max), RandomDouble(min, max));
}

inline vec3 RandomUnitVector()//兰伯特漫反射模型
{
	auto a = RandomDouble(0, 2 * PI);//随机0到2PI的一个值
	auto z = RandomDouble(-1, 1);//随机-1到1的一个值
	auto r = sqrt(1 - z * z);//对 （（1 - 随机在-1到1的值） 的结果） 进行开方
	return vec3(r * cos(a), r * sin(a), z);
}

inline double Clamp(double x, double min, double max)
{
	if (x < min)
	{
		return min;
	}
	if (x > max)
	{
		return max;
	}
	return x;
}

inline int TranslateColor(double x)
{
	return static_cast<int>(256 * Clamp(x, 0.0, 0.999));
}

inline vec3 RandomInHitUintSphere()//普通击中点单位球内随机反射方向
{
	while (true)
	{
		auto p = Random(-1, 1);
		if (p.squaredNorm() >= 1)
		{
			continue;
		}
		return p;
	}
}

inline vec3 RandomInHemisphere(const vec3& normal)//另一种漫反射模型
{
	vec3 inUnitSphere = RandomInHitUintSphere();
	if (inUnitSphere.dot(normal) > 0.0)
	{
		return inUnitSphere;
	}
	else
	{
		return -inUnitSphere;
	}
}

//光线反射
inline vec3 Reflect(const vec3& v, const vec3& n)
{
	return v - 2 * v.dot(n) * n;
}

//光线折射 斯涅尔折射定律
inline vec3 Refract(const vec3& uv, const vec3& n, double etaiOverEtat)
{
	auto cosTheta = -uv.dot(n);
	vec3 rOutPerp = etaiOverEtat * (uv + cosTheta * n);
	vec3 rOutParallel = -sqrt(fabs(1.0 - rOutPerp.squaredNorm())) * n;
	return rOutPerp + rOutParallel;
}

inline vec3 Vec3Mult(const vec3& v, const vec3& n)
{
	return vec3(v[0] * n[0], v[1] * n[1], v[2] * n[2]);
}

inline vec3 Vec3Unit(const vec3& v)
{
	return vec3(v[0] / v.norm(), v[1] / v.norm(), v[2] / v.norm());
}

inline double Schlick(double cosine, double refIdx)
{
	auto r0 = (1 - refIdx) / (1 + refIdx);
	r0 *= r0;
	return r0 + (1 - r0) * pow((1 - cosine), 5);
}

inline vec3 RandomInUnitDisk()
{
	while (true)
	{
		auto p = vec3(RandomDouble(-1, 1), RandomDouble(-1, 1), 0);
		if (p.squaredNorm() >= 1)
		{
			continue;
		}
		return p;
	}
}