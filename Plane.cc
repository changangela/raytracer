
#include "Plane.h"

Plane::Plane(Vec3 normal, Vec3 point, Vec3 surfaceColor, double transparency)
	: Shape(surfaceColor, transparency), normal(normal), point(point) {
}

Vec3 *Plane::intersectionPoint(const Vec3 &rayOrigin, const Vec3 &rayDirection) {
	double lambda = (Vec3::dot(normal, point) - Vec3::dot(normal, rayOrigin)) / Vec3::dot(normal, rayDirection);

	if (lambda > EPS) {
		return new Vec3(rayOrigin + rayDirection * lambda);
	} else return NULL;
}

double Plane::angle(const Vec3 &point, const Vec3 &rayDirection) {
	return acos(Vec3::dot(normal, rayDirection)/ (rayDirection.length() * normal.length()));
}