#pragma once
#include "rtUtility.h"
class Camera
{
public:
	Camera(point3 lookFrom, point3 lookAt, vec3 vup, double vfov, double aspectRatio);

	Ray getRay(double u, double v) const;

private:
	point3 origin;
	point3 lowerLeftCorner;
	vec3 horizontal;
	vec3 vertical;
};

