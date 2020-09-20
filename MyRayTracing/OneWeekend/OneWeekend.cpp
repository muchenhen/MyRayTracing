#include <iostream>
#include <fstream>
#include <ostream>
#include <Eigen/Eigen>
#include "ColorWriter.h"
#include "Ray.h"
#include "HittableList.h"
#include "Sphere.h"
#include "rtUtility.h"
#include "Camera.h"

using namespace std;

int main()
{
	// Image
	const auto aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);
	const int samplesPerPixel = 50;//多重采样次数
	const int maxDepth = 50;//限制光线着色函数递归次数

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
	world.add(make_shared<Sphere>(point3(0, 0, -1), 0.5));
	world.add(make_shared<Sphere>(point3(0, -100.5, -1), 100));

	//Camera
	Camera camera;

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
			Eigen::Vector3f pixel_color(0.0, 0.0, 0.0);
			for (int s = 0; s < samplesPerPixel; ++s)
			{
				auto u = (i + randomDouble()) / (double(image_width) - 1);
				auto v = (j + randomDouble()) / (double(image_height) - 1);
				u = clamp(u, 0.0, 1.0);
				v = clamp(v, 0.0, 1.0);
				Ray ray = camera.getRay(u,v);
				pixel_color += ColorWriter::RayColor(ray, world, maxDepth);
			}
			ColorWriter::write_color(outfile, pixel_color, samplesPerPixel);
			counti++;
		}
	}
	cerr << "\nDone.\n";
	cout << counti * countj;
	system("pause");
	return 0;
}
