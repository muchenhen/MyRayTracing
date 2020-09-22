#include "Lambertian.h"

Lambertian::Lambertian(const color3& a)
{
	albedo = a;
}

bool Lambertian::scatter(const Ray& RayIn, const hitRecord& record, color3& attenuation, Ray& scattered) const
{
	vec3 scatterDirection = record.normal + randomUnitVector();
	scattered = Ray(record.p, scatterDirection);
	attenuation = albedo;
	return true;
}
