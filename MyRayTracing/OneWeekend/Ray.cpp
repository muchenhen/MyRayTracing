#include "Ray.h"

Ray::Ray()
{
}

Ray::Ray(const point3& origen, const vec3& direction)
{
	orig = origen;
	dir = direction;
}

point3 Ray::GetOrigenPoint()
{
	return orig;
}

vec3 Ray::GetDirection()
{
	return dir;
}

point3 Ray::GetAtPoint(double t) const
{
	return orig + t * dir;
}
