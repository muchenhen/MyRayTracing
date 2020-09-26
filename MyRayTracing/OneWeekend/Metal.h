#pragma once
#include "Material.h"
class Metal : public Material
{
public:
	Metal(const color3& a);
	Metal(const color3& a, double f);

	virtual bool Scatter(const Ray& RayIn, const hitRecord& record, color3& attenuation, Ray& scattered) const override;

public:
	color3 albedo;
	double fuzz;//Ä£ºý
};

