#include "rtUtility.h"
#include <random>

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
