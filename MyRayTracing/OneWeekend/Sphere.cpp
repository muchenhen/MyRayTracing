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

bool Sphere::hit(const Ray& r, double t_min, double t_max, hitRecord& record) const
{
    vec3 oc = r.orig - center;//��Դ���������
	double a = double(r.dir.dot(r.dir));
	double half_b = oc.dot(r.dir);
	double c = oc.dot(oc) - radius * radius;
	auto discriminant = half_b * half_b - a * c;//b^2 - 4ac ����0 �н�

	if (discriminant > 0)
	{
		auto root = sqrt(discriminant);//�б�ʽ��ƽ����

		auto temp = (-half_b - root) / a;//һ����
		if (temp < t_max && temp > t_min)//���Ƿ��ڲ�����Χ��
		{
			record.t = temp;
			record.p = r.at(record.t);
			vec3 outwardNormal = (record.p - center) / radius;
			record.setFaceNormal(r, outwardNormal);
			return true;
		}

		temp = (-half_b + root) / a;//��һ����
		if (temp < t_max && temp > t_min)//
		{
			record.t = temp;
			record.p = r.at(record.t);
			vec3 outwardNormal = (record.p - center) / radius;
			record.setFaceNormal(r, outwardNormal);
			return true;
		}
	}

    return false;
}
