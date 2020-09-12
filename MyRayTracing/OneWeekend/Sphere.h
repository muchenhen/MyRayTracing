#pragma once
#include "Hittable.h"
class Sphere : public Hittable
{
public:
	Sphere();
	Sphere(point3 c, double r);
	virtual bool hit(const Ray& r, double t_min, double t_max, hitRecord& record) const override;

public:
	point3 center;
	double radius;
};

