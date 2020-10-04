#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <Eigen/Eigen>
#include "Material.h"
#include "Lambertian.h"
#include "Metal.h"
#include "Ray.h"
#include "Hittable.h"
#include "rtUtility.h"
using namespace std;


class ColorWriter
{
public:
	color3 pixel_color;

	static void WriteColor(ofstream& outfile, color3 pixel_color, int samplePerPixel);

	static color3 ray_color(const Ray& r);

	static color3 RayColor(const Ray& r, const Hittable& world, int depth);

	static color3 RayColor2(const Ray& r, const Hittable& world, int depth);

	static double HitSphere(const point3& center, double radius, const Ray& r);
};

