#include "HittableList.h"

HittableList::HittableList()
{
}

HittableList::HittableList(shared_ptr<Hittable> object)
{
	add(object);
}

void HittableList::clear()
{
	objects.clear();
}

void HittableList::add(shared_ptr<Hittable> object)
{
	objects.push_back(object);
}

bool HittableList::hit(const Ray& r, double tmin, double tmax, hitRecord& record) const
{
	hitRecord tempRecord;
	bool hitAnything = false;
	auto closestSoFar = tmax;
	for (const auto & object : objects)
	{
		if (object->hit(r, tmin, closestSoFar, tempRecord))
		{
			hitAnything = true;
			closestSoFar = tempRecord.t;
			record = tempRecord;
		}
	}
	return hitAnything;
}
