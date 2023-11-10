#ifndef  HITTABLE_H
#define  HITTABLE_H


#include "ray.h"
#include "vec3.h"

class hit_record
{
	public:
		vec3 p;
		vec3 normal;
		double t;
		bool front_face;
		void set_face_normal(const ray& r,const vec3& outward_normal)
		{

			// NOTE: outward normal is assumed to be normalized!
			front_face = dot(r.direction(), outward_normal);
			normal = front_face? outward_normal: -outward_normal;

		}
};


class hittable_object
{
	public: 
		virtual ~hittable_object() = default;

		virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;

};


#endif
