﻿#include <iostream>
#include <fstream>
#include <ostream>
#include <Eigen/Eigen>
#include "ColorWriter.h"
#include "Ray.h"
#include "HittableList.h"
#include "Sphere.h"
#include "rtUtility.h"
#include "Camera.h"
#include "Material.h"
#include "Lambertian.h"
#include "Metal.h"

using namespace std;

int main()
{
	// Image
	const auto aspect_ratio = 16.0 / 9.0;
	const int image_width = 1920;
	const int image_height = static_cast<int>(image_width / aspect_ratio);
	const int samplesPerPixel = 8;//多重采样次数
	const int maxDepth = 10;//限制光线着色函数递归次数

	// Open File
	ofstream outfile;
	outfile.open("image.ppm");
	if (outfile)
	{
		cout << "open file success!" << endl;
	}
	else
	{
		cout << "open file failed" << endl;
	}

	//World
	HittableList world;
 	/*world.add(make_shared<Sphere>(point3(0, 0, -1), 0.5));
 	world.add(make_shared<Sphere>(point3(0, -100.5, -1), 100));*/

	//Camera
	Camera camera;

	//Materials
	auto materialGround = make_shared<Lambertian>(color3(0.8, 0.8, 0.0));
	auto materialCenter = make_shared<Lambertian>(color3(0.7, 0.3, 0.3));
	auto materialLeft = make_shared<Metal>(color3(0.8, 0.8, 0.8));
	auto materialRight = make_shared<Metal>(color3(0.8, 0.6, 0.2));

	world.add(make_shared<Sphere>(point3( 0.0, -100.5, -1.0), 100.0, materialGround));
	world.add(make_shared<Sphere>(point3( 0.0,	  0.0, -1.0),   0.5, materialCenter));
	world.add(make_shared<Sphere>(point3(-1.0,    0.0, -1.0),   0.5, materialLeft));
	world.add(make_shared<Sphere>(point3( 1.0,    0.0, -1.0),   0.5, materialRight));

	// Render
	outfile << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	int countj = 0;
	int counti = 0;
	for (int j = image_height - 1; j >= 0; --j) 
	{
		countj++;
		cerr << "\rScanlines remaining: " << j << ' ' << flush;
		for (int i = 0; i < image_width; ++i) 
		{
			color3 pixel_color(0.0, 0.0, 0.0);
			for (int s = 0; s < samplesPerPixel; ++s)
			{
				auto u = (i + randomDouble()) / (double(image_width) - 1);
				auto v = (j + randomDouble()) / (double(image_height) - 1);
				u = clamp(u, 0.0, 1.0);
				v = clamp(v, 0.0, 1.0);
				Ray ray = camera.getRay(u,v);
				pixel_color += ColorWriter::RayColor2(ray, world, maxDepth);
			}
			ColorWriter::WriteColor(outfile, pixel_color, samplesPerPixel);
			counti++;
		}
	}
	cerr << "\nDone.\n";
	cout << counti * countj;
	system("pause");
	return 0;
}
