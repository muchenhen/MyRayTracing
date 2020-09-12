#pragma once
#include "Ray.h"

 struct hitRecord
{
	point3 p;
	vec3 normal;
	double t;

	bool front_face;

	inline void setFaceNormal(const Ray& r, const vec3& outwardNormal)
	{
		front_face = r.dir.dot(outwardNormal) < 0;
		normal = front_face ? outwardNormal : -outwardNormal;
	}
};

class Hittable
{
public:
	virtual bool hit(const Ray& r, double t_min, double t_max, hitRecord& rec)const = 0;
};

