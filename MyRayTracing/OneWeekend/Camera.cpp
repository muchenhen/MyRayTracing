#include "Camera.h"

Camera::Camera(point3 lookfrom,
	point3 lookat,
	vec3   vup,
	double vfov, // vertical field-of-view in degrees
	double aspect_ratio,
	double aperture,
	double focus_dist)
{
	auto theta = DegreesToRadians(vfov);
	auto h = tan(theta / 2);
	auto viewport_height = 2.0 * h;
	auto viewport_width = aspect_ratio * viewport_height;

	w = Vec3Unit(lookfrom - lookat);
	u = Vec3Unit(vup.cross(w));
	v = w.cross(u);

	origin = lookfrom;
	horizontal = focus_dist * viewport_width * u;
	vertical = focus_dist * viewport_height * v;
	lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - focus_dist * w;

	lens_radius = aperture / 2;
}

//返回根据UV偏移的光线
Ray Camera::GetRay(double s, double t) const
{
	vec3 rd = lens_radius * RandomInUnitDisk();
	vec3 offset = u * rd.x() + v * rd.y();

	return Ray(
		origin + offset,
		lowerLeftCorner + s * horizontal + t * vertical - origin - offset
	);
}
