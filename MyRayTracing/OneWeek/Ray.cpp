#include "Ray.h"

Ray::Ray()
{
}

Ray::Ray(const point3& origen, const vec3& direction)
{
	orig = origen;
	dir = direction;
}

Ray::Ray(const point3& origin, const vec3& direction, double time)
{
	orig = origin;
	dir = direction;
	tm = time;
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

double Ray::GetTime() const
{
	return tm;
}
