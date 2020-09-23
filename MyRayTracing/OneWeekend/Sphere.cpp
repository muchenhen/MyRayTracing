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
	materialPtr = nullptr;
}

//Sphere::Sphere(point3 c, double r, shared_ptr<Material> matptr)
//{
//	center = c;
//	radius = r;
//	materialPtr = matptr;
//}

Sphere::Sphere(point3 c, double r, shared_ptr<material> matptr)
{
	center = c;
	radius = r;
	materialPtr = matptr;
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
			vec3 outwardNormal = (record.p - center) / radius;//���м�¼�ĵ� ��ȥ ���ĵ� ������� ��뾶��
															  //���Եõ�һ������ķ��߷���
			record.setFaceNormal(r, outwardNormal);//�����뷨�߽����ж�
			if (materialPtr)
			{
				record.materialPtr = materialPtr;
			}
			return true;
		}

		temp = (-half_b + root) / a;//��һ����
		if (temp < t_max && temp > t_min)//
		{
			record.t = temp;
			record.p = r.at(record.t);
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

bool Sphere::hit2(const Ray& r, double t_min, double t_max, hitRecord& record)
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
			vec3 outwardNormal = (record.p - center) / radius;//���м�¼�ĵ� ��ȥ ���ĵ� ������� ��뾶��
															  //���Եõ�һ������ķ��߷���
			record.setFaceNormal(r, outwardNormal);//�����뷨�߽����ж�
			record.materialPtr = materialPtr;
			return true;
		}

		temp = (-half_b + root) / a;//��һ����
		if (temp < t_max && temp > t_min)//
		{
			record.t = temp;
			record.p = r.at(record.t);
			vec3 outwardNormal = (record.p - center) / radius;
			record.setFaceNormal(r, outwardNormal);
			record.materialPtr = materialPtr;
			return true;
		}
	}

	return false;
}
