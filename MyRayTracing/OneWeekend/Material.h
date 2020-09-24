#pragma once
#include "rtUtility.h"
#include "Hittable.h"

class Material
{
public:
	virtual bool Scatter(const Ray& r_in, const hitRecord& rec, color3& attenuation, Ray& scattered) const = 0;
};
