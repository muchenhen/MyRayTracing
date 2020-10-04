#pragma once
#include "Material.h"
class Dielectric : public Material
{
public:
	Dielectric(double ri);

	virtual bool Scatter(const Ray& r_in, const hitRecord& rec, color3& attenuation, Ray& scattered) const override;

public:
	double refIndex;
};

