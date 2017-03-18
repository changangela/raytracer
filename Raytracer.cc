
#include "Cylinder.h"
#include "Sphere.h"
#include "Plane.h"
#include "Scene.h"
#include "ImageWriter.h"
#include "Vec3.h"

#include <iostream>
using namespace std;


void test() {
  Vec3 a = Vec3(0,0,1); 
  Vec3 b = Vec3(0,1,1); 

  Vec3 out = Vec3::rotate(a,b,PI);
  out.print(); 
}


int main () {
	Camera c(Vec3(0,0,0), Vec3(0,0,1), 90, 90, 0, 1080, 1080);
	Scene s(c);

	Sphere sph1 = Sphere(Vec3(0, -3, 20), 2, Vec3(20, 102, 20), 1, 0);
	Sphere sph2 = Sphere(Vec3(0, -3, 10), 2, Vec3(100, 40, 20), 1.1, 1.1);
	Sphere sph3 = Sphere(Vec3(4, -3, 20), 2, Vec3(12, 32, 123), 1, 0);
	Sphere sph4 = Sphere(Vec3(-4, -3, 20), 2, Vec3(130, 0, 0), 1, 0);

	Plane pla1 = Plane(Vec3(0, -3, 0), Vec3(0,-6, 100), Vec3(200, 170, 190), 0.4, 0);
//	Plane pla2 = Plane(Vec3(0, 0, -1), Vec3(0, 0, 100), Vec3(46, 220, 32), 0.3, 0);

	s.AddShape(&sph1);
	s.AddShape(&sph2);
  	s.AddShape(&sph3);
  	s.AddShape(&sph4);
	s.AddShape(&pla1);
//	s.AddShape(&pla2);

	Light l(Vec3(0, 15, 0), Vec3(0, 0, 5));

	s.AddLight(&l);

	// cout << sph.intersectionPoint(Vec3(0,0,-5), Vec3 (0,0,1))->X() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Y() << sph.intersectionPoint(Vec3(0,0,-5), Vec3(0,0,1))->Z() << endl;

	ImageWriter::write(s.Render());
}
