#ifndef  SPHERE_H
#define  SPHERE_H

#include "hittable.h"
#include "vec3.h"
#include "ray.h"

/* class sphere : public hittable_object { */
class sphere : public hittable_object {
	public: 
		sphere(point3 _center,double _radius);
		virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec)const override;
		/* { */
		/* 	return true; */
		/* }; */
	private:
		point3 center;
		double radius; 

};


#endif
