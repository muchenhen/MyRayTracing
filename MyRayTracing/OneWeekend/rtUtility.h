/*
��¼��ѧ����
*/
#pragma once
#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <random>
#include <iostream>
#include "Ray.h"

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();//�����
const double PI = 3.1415926535897932385;//Բ����



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

inline vec3 randomUnitVector()
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

inline vec3 randomInHitUintSphere()
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