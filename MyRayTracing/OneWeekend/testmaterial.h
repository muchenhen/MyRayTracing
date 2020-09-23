#pragma once
#include "rtUtility.h"
#include "Hittable.h"

class material {
public:
	virtual bool scatter(
		const Ray& r_in, const hitRecord& rec, color3& attenuation, Ray& scattered
	) const = 0;
};

class lambertian : public material {
public:
	lambertian(const color3& a) : albedo(a) {}

	virtual bool scatter(
		const Ray& r_in, const hitRecord& rec, color3& attenuation, Ray& scattered
	) const override {
		vec3 scatter_direction = rec.normal + randomUnitVector();
		scattered = Ray(rec.p, scatter_direction);
		attenuation = albedo;
		return true;
	}

public:
	color3 albedo;
};

class metal : public material {
public:
	metal(const color3& a) : albedo(a) {}

	virtual bool scatter(
		const Ray& r_in, const hitRecord& rec, color3& attenuation, Ray& scattered
	) const override {
		vec3 reflected = reflect(unitVec3(r_in.dir), rec.normal);
		scattered = Ray(rec.p, reflected);
		attenuation = albedo;
		return (scattered.dir.dot(rec.normal) > 0);
	}

public:
	color3 albedo;
};