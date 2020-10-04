#pragma once
#include <Eigen/Eigen>

using point3 = Eigen::Vector3d;
using vec3 = Eigen::Vector3d;

class Ray
{
public:
	Ray();
	Ray(const point3& origen, const vec3& direction);
	Ray(const point3& origin, const vec3& direction, double time);
	point3 GetOrigenPoint();
	vec3 GetDirection();
	point3 GetAtPoint(double t) const;
	double GetTime() const;

public:
	point3 orig;
	vec3 dir;
	double tm = 0.0;
};

