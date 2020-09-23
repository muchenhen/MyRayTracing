#pragma once
#include "rtUtility.h"
#include "Hittable.h"

class Material
{
public:
	virtual bool Scatter(const Ray& RayIn, const hitRecord& record, color3& attenuation, Ray& scattered) const = 0;
};
