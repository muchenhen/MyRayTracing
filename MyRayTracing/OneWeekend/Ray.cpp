#include "Ray.h"

Ray::Ray()
{
}

Ray::Ray(const point3& origen, const vec3& direction)
{
	orig = origen;
	dir = direction;
}

point3 Ray::origen()
{
	return orig;
}

vec3 Ray::direction()
{
	return dir;
}

point3 Ray::at(double t) const
{
	return orig + t * dir;
}
