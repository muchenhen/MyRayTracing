#pragma once
#include <Eigen/Eigen>

using point3 = Eigen::Vector3d;
using vec3 = Eigen::Vector3d;

class Ray
{
public:
	Ray();
	Ray(const point3& origen, const vec3& direction);
	point3 origen();
	vec3 direction();
	point3 at(double t) const;

public:
	point3 orig;
	vec3 dir;
};

