/*
记录数学常量
*/
#pragma once
#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <random>
#include "Ray.h"

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
