#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <Eigen/Eigen>
#include "Ray.h"
#include "Hittable.h"
using namespace std;
using point3 = Eigen::Vector3f;

class color
{
public:
	Eigen::Vector3f pixel_color;

	static void write_color(ofstream& outfile, Eigen::Vector3f pixel_color, int samplePerPixel);

	static Eigen::Vector3f ray_color(const Ray& r);

	static Eigen::Vector3f RayColor(const Ray& r, const Hittable& world);

	static double hit_sphere(const point3& center, double radius, const Ray& r);
};

