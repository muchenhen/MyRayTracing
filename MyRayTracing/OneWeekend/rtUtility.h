/*
记录数学常量
*/
#pragma once
#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include "Ray.h"

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();//无穷大
const double PI = 3.1415926535897932385;//圆周率

inline double degreesToRadians(double degress);//角弧度转换

inline double randomDouble();

inline double randomDouble(double min, double max);