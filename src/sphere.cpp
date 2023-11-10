
#include "sphere.h"

sphere::sphere(point3 _center,double _radius):center(_center), radius(_radius) {};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const
{

	vec3 oc = r.origin()-center;

	auto a = r.direction().length_squared();
	auto half_b = dot(oc,r.direction());

	auto c = oc.length_squared() - radius*radius;



	auto discriminant= half_b*half_b;
	if(discriminant<0) return false;

	auto sqrt_discriminant = sqrt(discriminant);

	auto root = (-half_b -sqrt_discriminant) / a;

	// we want the root to be within the timewindow
	if(root <= t_min || t_max <=root) {
		root = (-half_b + sqrt_discriminant)/ a;
		if (root <= t_min || t_max <= root)
			return false;
	}
	rec.t = root;
	rec.p = r.at(rec.t);
	// determine at which direction the ray is coming from
	// we only detect hits at the edge => we know we are at max r!
	vec3 outward_normal = (rec.p - center) / radius; 
	rec.set_face_normal(r, outward_normal);


	rec.normal = (rec.p - center) / radius;

	return true;
}


