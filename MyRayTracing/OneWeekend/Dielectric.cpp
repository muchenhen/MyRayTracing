#include "Dielectric.h"

Dielectric::Dielectric(double ri)
{
	refIndex = ri;
}

bool Dielectric::Scatter(const Ray& r_in, const hitRecord& rec, color3& attenuation, Ray& scattered) const
{
	attenuation = color3(1.0, 1.0, 1.0);
	double etaiOverEtat = rec.frontFace ? (1.0 / refIndex) : refIndex;
	vec3 unitDirection = Vec3Unit(r_in.dir);

	//ȫ�ڷ��� û������
	double cosTheta = fmin(-unitDirection.dot(rec.normal), 1.0);
	double sinTheta = sqrt(1.0 - cosTheta * cosTheta);
	if (etaiOverEtat * sinTheta > 1.0)
	{
		vec3 refracted = Reflect(unitDirection, rec.normal);
		scattered = Ray(rec.p, refracted);
		return true;
	}

	vec3 refracted = Refract(unitDirection, rec.normal, etaiOverEtat);
	scattered = Ray(rec.p, refracted);
	return true;
}
