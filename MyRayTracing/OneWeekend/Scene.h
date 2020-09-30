#pragma once
#include "HittableList.h"
#include "Sphere.h"
#include "Dielectric.h"
#include "Metal.h"
#include "Lambertian.h"
#include "rtUtility.h"

HittableList RandomScene()
{
	HittableList world;
	auto groundMaterial = make_shared<Lambertian>(color3(0.5, 0.5, 0.5));
	world.add(make_shared<Sphere>(point3(0,-1000,0),1000,groundMaterial));

	for (int i = -11; i < 11; i++)
	{
		for (int j = -11; j < 11; j++)
		{
			auto chooseMat = RandomDouble();
			point3 center(i + 0.9 * RandomDouble(), 0.2, j + 0.9 * RandomDouble());

			if ((center - point3(4, 0.2, 0)).norm() > 0.9)
			{
				shared_ptr<Material> sphereMaterial;

				if (chooseMat < 0.8)
				{
					// diffuse
					color3 albedo = Vec3Mult(Random(), Random());
					sphereMaterial = make_shared<Lambertian>(albedo);
					world.add(make_shared<Sphere>(center, 0.2, sphereMaterial));
				}
				else if(chooseMat < 0.95)
				{
					// metal
					color3 albedo = Random(0.5, 1);
					double fuzz = RandomDouble(0, 0.5);
					sphereMaterial = make_shared<Metal>(albedo, fuzz);
					world.add(make_shared<Sphere>(center, 0.2, sphereMaterial));
				}
				else
				{
					// glass
					sphereMaterial = make_shared<Dielectric>(1.5);
					world.add(make_shared<Sphere>(center, 0.2, sphereMaterial));
				}
			}
		}
	}

	auto material01 = make_shared<Dielectric>(1.5);
	world.add(make_shared<Sphere>(point3(0, 1, 0), 1.0, material01));

	auto material02 = make_shared<Lambertian>(color3(0.4, 0.2, 0.1));
	world.add(make_shared<Sphere>(point3(-4, 1, 0), 1.0, material02));

	auto material03 = make_shared<Metal>(color3(0.7, 0.6, 0.5), 0.0);
	world.add(make_shared<Sphere>(point3(4, 1, 0), 1.0, material03));

	return world;
}