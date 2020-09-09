#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include <Eigen/Eigen>
#include "Ray.h"
using namespace std;


class color
{
public:
	Eigen::Vector3f pixel_color;

	static void write_color(ofstream& outfile, Eigen::Vector3f pixel_color);

	static Eigen::Vector3f ray_color(const Ray& r);
};

