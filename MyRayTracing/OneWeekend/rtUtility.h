#pragma once
#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include "Ray.h"

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double PI = 3.1415926535897932385;

inline double degreesToRadians(double degress)
{
	return degress * PI / 180.0;
}
