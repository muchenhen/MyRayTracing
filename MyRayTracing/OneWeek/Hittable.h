#pragma once
#include "rtUtility.h"
#include "Ray.h"
/*
������¼���ǻ��е㣬���ǹ���ɨ��ʱ�������ཻ�ĵ㣬��Щ��һ����������
*/

class Material;

 struct hitRecord
{
	point3 p;//���λ��
	vec3 normal;//�õ�ķ���
	shared_ptr<Material> materialPtr;
	double t;//���иõ�Ĺ��ߵĲ���t��ֵ

	bool frontFace;//�Ƿ��ǳ�������ķ���

	inline void setFaceNormal(const Ray& r, const vec3& outwardNormal)
	{
		frontFace = r.dir.dot(outwardNormal) < 0;
		normal = frontFace ? outwardNormal : -outwardNormal;
	}
};

class Hittable
{
public:
	virtual bool hit(const Ray& r, double t_min, double t_max, hitRecord& rec)const = 0;
};

