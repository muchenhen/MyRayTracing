#pragma once
#include "rtUtility.h"
#include "Ray.h"
/*
这个类记录的是击中点，就是光线扫描时和球面相交的点，这些点一定在球面上
*/

class Material;

 struct hitRecord
{
	point3 p;//点的位置
	vec3 normal;//该点的法线
	shared_ptr<Material> materialPtr;
	double t;//击中该点的光线的参数t的值

	bool frontFace;//是否是朝向外面的法线

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

