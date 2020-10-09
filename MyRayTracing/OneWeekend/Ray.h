#pragma once
#include <Eigen/Eigen>

using point3 = Eigen::Vector3d;
using vec3 = Eigen::Vector3d;

class Ray
{
public:
	Ray();
	Ray(const point3& origen, const vec3& direction);
	point3 GetOrigenPoint();
	vec3 GetDirection();
	point3 GetAtPoint(double t) const;

public:
	point3 orig;
	vec3 dir;
};

