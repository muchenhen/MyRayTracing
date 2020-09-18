#pragma once
#include "rtUtility.h"
class Camera
{
public:
	Camera();

	Ray getRay(double u, double v) const;

private:
	point3 origin;
	point3 lowerLeftCorner;
	vec3 horizontal;
	vec3 vertical;
};
