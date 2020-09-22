#pragma once
#include "Material.h"
class Metal : public Material
{
public:
	Metal(const color3& a);

	virtual bool scatter(const Ray& RayIn, const hitRecord& record, color3& attenuation, Ray& scattered) const override;

public:
	color3 albedo;
};

