#include <iostream>
#include <fstream>
#include <ostream>
#include <Eigen/Eigen>
#include "color.h"
#include "Ray.h"
using namespace std;

int main()
{
	// Image
	const auto aspect_ratio = 16.0 / 9.0;
	const int image_width = 400;
	const int image_height = static_cast<int>(image_width / aspect_ratio);

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

	// Render
	outfile << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	for (int j = image_height - 1; j >= 0; --j) 
	{
		cerr << "\rScanlines remaining: " << j << ' ' << flush;
		for (int i = 0; i < image_width; ++i) 
		{
			Eigen::Vector3f pixel_color;
			float r = float(i) / (float(image_width) - 1);
			float g = float(j) / (float(image_height) - 1);
			float b = 0.25;
			pixel_color = { r,g,b };
			color::write_color(outfile, pixel_color);
		}
	}
	cerr << "\nDone.\n";
	system("pause");
	return 0;
}
