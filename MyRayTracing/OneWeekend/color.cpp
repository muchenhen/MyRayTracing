#include "color.h"
#include <math.h>

void color::write_color(ofstream& outfile, Eigen::Vector3f pixel_color)
{
	outfile << static_cast<int>(255.999 * pixel_color[0]) << ' '
		<< static_cast<int>(255.999 * pixel_color[1]) << ' '
		<< static_cast<int>(255.999 * pixel_color[2]) << '\n';
}

Eigen::Vector3f color::ray_color(const Ray& r)
{
	//击中球的时候走这里着色
	auto t = hit_sphere(point3(0, 0, -1), 0.5, r);
	if (t > 0.0)
	{
		vec3 N = (r.at(t) - vec3(0, 0, -1));
		N = N.normalized();
		N = (N + Eigen::Vector3f(0.5, 0.7, 1.0)) * 0.5;
		return N;
	}
	//没有击中球的时候按照原本的背景计算颜色
	vec3 unit_direction = r.dir;
	unit_direction = unit_direction.normalized();
	t = 0.5 * (unit_direction[1] + 1.0);
	return (1.0 - t) * Eigen::Vector3f(1.0, 1.0, 1.0) + t * Eigen::Vector3f(0.5, 0.7, 1.0);
}

//判断球是否被击中
double color::hit_sphere(const point3& center, double radius, const Ray& r)
{
	vec3 oc = r.orig - center;
	double a = double(r.dir.dot(r.dir));
	double half_b = oc.dot(r.dir);
	double c = oc.dot(oc) - radius * radius;
	auto discriminant = half_b * half_b - a * c;//b^2 - 4ac 大于0 有解
	if (discriminant < 0)
	{
		return -1.0;
	}
	else
	{
		return (-half_b - sqrt(discriminant)) * a;
	}
}
