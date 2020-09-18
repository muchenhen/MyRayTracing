#include "Camera.h"

Camera::Camera()
{
	double aspectRatio = 16.0 / 9.0;//��߱�
	double viewportHeight = 2.0;//�ӿڸ߶�
	double viewportWidth = aspectRatio * viewportHeight;//�ӿڿ��
	double focalLength = 1.0;//���� ����ָ��������ӿ���Ƭ�ľ���

	origin = point3(0, 0, 0);//��Դλ��
	horizontal = vec3(viewportWidth, 0.0, 0.0);//ˮƽ��
	vertical = vec3(0.0, viewportHeight, 0.0);//��ֱ��
	lowerLeftCorner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focalLength);//�ӿڵ����½�λ��
}

//���ظ���UVƫ�ƵĹ���
Ray Camera::getRay(double u, double v) const
{
	return Ray(origin, lowerLeftCorner + u * horizontal + v * vertical - origin);
}
