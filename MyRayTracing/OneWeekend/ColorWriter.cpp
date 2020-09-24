#include <math.h>
#include "ColorWriter.h"
#include "HittableList.h"
#include "sphere.h"
#include "rtUtility.h"


void ColorWriter::WriteColor(ofstream& outfile, color3 pixel_color, int samplePerPixel)
{
	auto r = pixel_color[0];
	auto g = pixel_color[1];
	auto b = pixel_color[2];

	//����ɫ���Բ���ϵ��
	auto scale = 1.0 / samplePerPixel;
	//gamma���� Gamma2 ֱ�ӿ���
	r = sqrt(r * scale);
	g = sqrt(g * scale);
	b = sqrt(b * scale);

	//rgbת����0~255��д�뵽�ļ�

	outfile << translateColor(r) << ' '
		<< translateColor(g) << ' '
		<< translateColor(b) << '\n';
}

color3 ColorWriter::ray_color(const Ray& r)
{
	//�������ʱ����������ɫ
	auto t = HitSphere(point3(0, 0, -1), 0.5, r);
	if (t > 0.0)
	{
		vec3 N = (r.at(t) - vec3(0, 0, -1));
		N = N.normalized();
		N = (N + color3 (0.5, 0.7, 1.0)) * 0.5;
		return N;
	}
	//û�л������ʱ����ԭ���ı���������ɫ
	vec3 unit_direction = r.dir;
	unit_direction = unit_direction.normalized();
	t = 0.5 * (unit_direction[1] + 1.0);
	return (1.0 - t) * color3(1.0, 1.0, 1.0) + t * color3(0.5, 0.7, 1.0);
}

color3 ColorWriter::RayColor(const Ray& r, const Hittable& world, int depth)
{
	hitRecord record;
	if (depth <= 0)
	{
		return color3(0, 0, 0);
	}

	if (world.hit(r, 0.001, infinity, record))
	{
		point3 target = record.p + randomInHemisphere(record.normal);//���е�λ�� + ���е㷨�� = �����Χ��λ�������λ�ã�
		/*�Ѿ�����Ϊ������ģ��*/
		/*�ָĳ�����һ��������ģ��*/
		//����λ�� + ���ƫ�ƣ�������-1 ��1����ΪҪ�����ڵ�λ��֮�ڣ� = ��Ϊ��������ߵ��յ�����

		return 0.5 * RayColor(Ray(record.p, target - record.p), world, depth - 1);
	}
	vec3 unitDirection = r.dir.normalized();
	auto t = 0.5 * (unitDirection[2] + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

color3 ColorWriter::RayColor2(const Ray& r, const Hittable& world, int depth)
{
	hitRecord record;

	if (depth <= 0)
	{
		return color3(0, 0, 0);
	}

	if (world.hit(r, 0.001, infinity, record))
	{
		Ray scattered;
		color3 attenuation;
		if (record.materialPtr->Scatter(r, record, attenuation, scattered))
		{
			return  vec3Mult(attenuation, ColorWriter::RayColor2(scattered, world, depth - 1));
		}
		else
		{
			return color3(0, 0, 0);
		}
	}

	vec3 unitDirection = vec3Unit(r.dir);
	auto t = 0.5 * (unitDirection[2] + 1.0);
	return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}

//�ж����Ƿ񱻻���
double ColorWriter::HitSphere(const point3& center, double radius, const Ray& r)
{
	vec3 oc = r.orig - center;
	double a = double(r.dir.dot(r.dir));
	double half_b = oc.dot(r.dir);
	double c = oc.dot(oc) - radius * radius;
	auto discriminant = half_b * half_b - a * c;//b^2 - 4ac ����0 �н�
	if (discriminant < 0)
	{
		return -1.0;
	}
	else
	{
		return (-half_b - sqrt(discriminant)) * a;
	}
}
