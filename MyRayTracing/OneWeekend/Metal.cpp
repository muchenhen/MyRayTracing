#include "Metal.h"

Metal::Metal(const color3& a)
{
	albedo = a;
}

bool Metal::scatter(const Ray& RayIn, const hitRecord& record, color3& attenuation, Ray& scattered) const
{
	vec3 reflected = reflect(RayIn.dir.normalized(), record.normal);
	scattered = Ray(record.p, reflected);
	if (scattered.dir.dot(record.normal) > 0)
	{
		return true;
	} 
	else
	{
		return false;
	}
}
