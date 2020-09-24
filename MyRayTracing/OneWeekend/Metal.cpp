#include "Metal.h"

Metal::Metal(const color3& a)
{
	albedo = a;
}

bool Metal::Scatter(const Ray& RayIn, const hitRecord& record, color3& attenuation, Ray& scattered) const
{
	vec3 reflected = reflect(RayIn.dir.normalized(), record.normal);
	scattered = Ray(record.p, reflected);
	attenuation = albedo;
	return (scattered.dir.dot(record.normal) > 0);
}
