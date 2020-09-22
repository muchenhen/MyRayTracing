#pragma once
#include "Ray.h"
/*
������¼���ǻ��е㣬���ǹ���ɨ��ʱ�������ཻ�ĵ㣬��Щ��һ����������
*/
<<<<<<< HEAD

class Material;

=======
>>>>>>> parent of 3f5adbc... 4.65
 struct hitRecord
{
	point3 p;//���λ��
	vec3 normal;//�õ�ķ���
	shared_ptr<Material> materialPtr;
	double t;//���иõ�Ĺ��ߵĲ���t��ֵ

	bool front_face;//�Ƿ��ǳ�������ķ���

	inline void setFaceNormal(const Ray& r, const vec3& outwardNormal)
	{
		front_face = r.dir.dot(outwardNormal) < 0;
		normal = front_face ? outwardNormal : -outwardNormal;
	}
};

class Hittable
{
public:
	virtual bool hit(const Ray& r, double t_min, double t_max, hitRecord& rec)const = 0;
};

