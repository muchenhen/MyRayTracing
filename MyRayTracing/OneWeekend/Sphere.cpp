#include "Sphere.h"

Sphere::Sphere()
{
	center = point3(0, 0, 0);
	radius = 1.0;
}

Sphere::Sphere(point3 c, double r)
{
	center = c;
	radius = r;
}

Sphere::Sphere(point3 c, double r, shared_ptr<Material> matptr)
{
	center = c;
	radius = r;
	materialPtr = matptr;
}

bool Sphere::hit(const Ray& r, double t_min, double t_max, hitRecord& record) const
{
    vec3 oc = r.orig - center;//光源到球的中心
	double a = double(r.dir.dot(r.dir));
	double half_b = oc.dot(r.dir);
	double c = oc.dot(oc) - radius * radius;
	auto discriminant = half_b * half_b - a * c;//b^2 - 4ac 大于0 有解

	if (discriminant > 0)
	{
		auto root = sqrt(discriminant);//判别式的平方根

		auto temp = (-half_b - root) / a;//一个解
		if (temp < t_max && temp > t_min)//解是否在参数范围内
		{
			record.t = temp;
			record.p = r.GetAtPoint(record.t);
			vec3 outwardNormal = (record.p - center) / radius;//击中记录的点 减去 球心点 结果除以 球半径，
															  //可以得到一个向外的法线方向
			record.setFaceNormal(r, outwardNormal);//光线与法线进行判断
			if (materialPtr)
			{
				record.materialPtr = materialPtr;
			}
			return true;
		}

		temp = (-half_b + root) / a;//另一个解
		if (temp < t_max && temp > t_min)//
		{
			record.t = temp;
			record.p = r.GetAtPoint(record.t);
			vec3 outwardNormal = (record.p - center) / radius;
			record.setFaceNormal(r, outwardNormal);
			if (materialPtr)
			{
				record.materialPtr = materialPtr;
			}
			return true;
		}
	}

    return false;
}
