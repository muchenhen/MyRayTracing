#include "Camera.h"

Camera::Camera(point3 lookFrom, point3 lookAt, vec3 vup, double vfov, double aspectRatio)
{
	auto theta = DegreesToRadians(vfov);
	auto h = tan(theta / 2);
	auto viewportHeight = 2.0 * h;
	auto viewportWidth = aspectRatio * viewportHeight;//aspectRatio ��߱�

	auto w = Vec3Unit(lookFrom - lookAt);
	auto u = Vec3Unit(vup.cross(w));
	auto v = w.cross(u);
	
	double aspectRatioviewportHeight = 2.0;//�ӿڸ߶�
	double focalLength = 1.0;//���� ����ָ��������ӿ���Ƭ�ľ���

	origin = lookFrom;//��Դλ��
	horizontal = viewportWidth * u;//ˮƽ��
	vertical = viewportHeight * v;//��ֱ��
	lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - w;//�ӿڵ����½�λ��
}

//���ظ���UVƫ�ƵĹ���
Ray Camera::getRay(double u, double v) const
{
	return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}
