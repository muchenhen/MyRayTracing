#include "Camera.h"

Camera::Camera(double vfov, double aspectRatio)
{
	auto theta = DegreesToRadians(vfov);
	auto h = tan(theta / 2);
	auto viewportHeight = 2.0 * h;
	auto viewportWidth = aspectRatio * viewportHeight;

	//double aspectRatio = 16.0 / 9.0;//宽高比
	double aspectRatioviewportHeight = 2.0;//视口高度
	//double viewportWidth = aspectRatio * viewportHeight;//视口宽度
	double focalLength = 1.0;//焦距 这里指摄像机和视口面片的距离

	origin = point3(0, 0, 0);//光源位置
	horizontal = vec3(viewportWidth, 0.0, 0.0);//水平线
	vertical = vec3(0.0, viewportHeight, 0.0);//垂直线
	lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focalLength);//视口的左下角位置
}

//返回根据UV偏移的光线
Ray Camera::getRay(double u, double v) const
{
	return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}
