#pragma once
#include "Hittable.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class HittableList : public Hittable
{
public:
	HittableList();
	HittableList(shared_ptr<Hittable> object);

	void clear();
	void add(shared_ptr<Hittable> object);

	virtual bool hit(const Ray& r, double tmin, double tmax, hitRecord& record) const override;

public:
	std::vector<shared_ptr<Hittable>> objects;
};

