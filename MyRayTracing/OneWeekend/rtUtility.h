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
using point3 = Eigen::Vector3f;
using color3 = Eigen::Vector3f;

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();//无穷大
const double PI = 3.1415926535897932385;//圆周率



inline double degreesToRadians(double degress)
{
	return degress * PI / 180.0;
}

inline double randomDouble()
{
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);
	static std::mt19937 generator;
	return distribution(generator);
}

inline double randomDouble(double min, double max)
{
	return min + (max - min) * randomDouble();
}

inline vec3 random()
{
	return vec3(randomDouble(), randomDouble(), randomDouble());
}

inline vec3 random(double min, double max)
{
	return vec3(randomDouble(min, max), randomDouble(min, max), randomDouble(min, max));
}

inline vec3 randomUnitVector()//兰伯特漫反射模型
{
	auto a = randomDouble(0, 2 * PI);
	auto z = randomDouble(-1, 1);
	auto r = sqrt(1 - z * z);
	return vec3(r * cos(a), r * sin(a), z);
}

inline double clamp(double x, double min, double max)
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

inline int translateColor(double x)
{
	return static_cast<int>(256 * clamp(x, 0.0, 0.999));
}

inline vec3 randomInHitUintSphere()//普通击中点单位球内随机反射方向
{
	while (true)
	{
		auto p = random(-1, 1);
		if (p.squaredNorm() >= 1)
		{
			continue;
		}
		return p;
	}
}

inline vec3 randomInHemisphere(const vec3& normal)//另一种漫反射模型
{
	vec3 inUnitSphere = randomInHitUintSphere();
	if (inUnitSphere.dot(normal) > 0.0)
	{
		return inUnitSphere;
	}
	else
	{
		return -inUnitSphere;
	}
}

inline vec3 reflect(const vec3& v, const vec3& n)
{
	return v - 2 * v.dot(n) * n;
}