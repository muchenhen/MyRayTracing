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
<<<<<<< HEAD:MyRayTracing/OneWeekend/ColorWriter.h

=======
using point3 = Eigen::Vector3f;
>>>>>>> parent of 3f5adbc... 4.65:MyRayTracing/OneWeekend/color.h

class color
{
public:
	Eigen::Vector3f pixel_color;

	static void write_color(ofstream& outfile, Eigen::Vector3f pixel_color, int samplePerPixel);

	static color3 ray_color(const Ray& r);

	static color3 RayColor(const Ray& r, const Hittable& world, int depth);

	static color3 RayColor2(const Ray& r, const Hittable& world, int depth);

	static double hit_sphere(const point3& center, double radius, const Ray& r);
};

