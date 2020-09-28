#include "Camera.h"

Camera::Camera(point3 lookFrom, point3 lookAt, vec3 vup, double vfov, double aspectRatio)
{
	auto theta = DegreesToRadians(vfov);
	auto h = tan(theta / 2);
	auto viewportHeight = 2.0 * h;
	auto viewportWidth = aspectRatio * viewportHeight;//aspectRatio 宽高比

	auto w = Vec3Unit(lookFrom - lookAt);
	auto u = Vec3Unit(vup.cross(w));
	auto v = w.cross(u);
	
	double aspectRatioviewportHeight = 2.0;//视口高度
	double focalLength = 1.0;//焦距 这里指摄像机和视口面片的距离

	origin = lookFrom;//光源位置
	horizontal = viewportWidth * u;//水平线
	vertical = viewportHeight * v;//垂直线
	lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - w;//视口的左下角位置
}

//返回根据UV偏移的光线
Ray Camera::getRay(double u, double v) const
{
	return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}
