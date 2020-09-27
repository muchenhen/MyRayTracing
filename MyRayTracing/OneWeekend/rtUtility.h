/*
��¼��ѧ����
*/
#pragma once
#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <random>
#include <iostream>
#include "Ray.h"

using point3 = Eigen::Vector3d;
using color3 = Eigen::Vector3d;

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();//�����
const double PI = 3.14159265;//Բ����

inline double DegreesToRadians(double degress)
{
	return degress * PI / 180.0;
}

inline double RandomDouble()
{
	static std::uniform_real_distribution<double> distribution(0.0, 1.0);
	static std::mt19937 generator;
	return distribution(generator);
}

inline double RandomDouble(double min, double max)
{
	return min + (max - min) * RandomDouble();
}

inline vec3 Random()
{
	return vec3(RandomDouble(), RandomDouble(), RandomDouble());
}

inline vec3 Random(double min, double max)
{
	return vec3(RandomDouble(min, max), RandomDouble(min, max), RandomDouble(min, max));
}

inline vec3 RandomUnitVector()//������������ģ��
{
	auto a = RandomDouble(0, 2 * PI);//���0��2PI��һ��ֵ
	auto z = RandomDouble(-1, 1);//���-1��1��һ��ֵ
	auto r = sqrt(1 - z * z);//�� ����1 - �����-1��1��ֵ�� �Ľ���� ���п���
	return vec3(r * cos(a), r * sin(a), z);
}

inline double Clamp(double x, double min, double max)
{
	if (x < min)
	{
		return min;
	}
	if (x > max)
	{
		return max;
	}
	return x;
}

inline int TranslateColor(double x)
{
	return static_cast<int>(256 * Clamp(x, 0.0, 0.999));
}

inline vec3 RandomInHitUintSphere()//��ͨ���е㵥λ����������䷽��
{
	while (true)
	{
		auto p = Random(-1, 1);
		if (p.squaredNorm() >= 1)
		{
			continue;
		}
		return p;
	}
}

inline vec3 RandomInHemisphere(const vec3& normal)//��һ��������ģ��
{
	vec3 inUnitSphere = RandomInHitUintSphere();
	if (inUnitSphere.dot(normal) > 0.0)
	{
		return inUnitSphere;
	}
	else
	{
		return -inUnitSphere;
	}
}

//���߷���
inline vec3 Reflect(const vec3& v, const vec3& n)
{
	return v - 2 * v.dot(n) * n;
}

//�������� ˹�������䶨��
inline vec3 Refract(const vec3& uv, const vec3& n, double etaiOverEtat)
{
	auto cosTheta = -uv.dot(n);
	vec3 rOutPerp = etaiOverEtat * (uv + cosTheta * n);
	vec3 rOutParallel = -sqrt(fabs(1.0 - rOutPerp.squaredNorm())) * n;
	return rOutPerp + rOutParallel;
}

inline vec3 Vec3Mult(const vec3& v, const vec3& n)
{
	return vec3(v[0] * n[0], v[1] * n[1], v[2] * n[2]);
}

inline vec3 Vec3Unit(const vec3& v)
{
	return vec3(v[0] / v.norm(), v[1] / v.norm(), v[2] / v.norm());
}

inline double Schlick(double cosine, double refIdx)
{
	auto r0 = (1 - refIdx) / (1 + refIdx);
	r0 *= r0;
	return r0 + (1 - r0) * pow((1 - cosine), 5);
}