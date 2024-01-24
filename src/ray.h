#ifndef RAY_H
#define RAY_H



#include "vec3.h"

const int max_bounces = 10;

class ray {

	public:
		ray(): bounce_count(0) {}
		ray(const point3& origin, const vec3& direction): orig(origin),dir(direction), bounce_count(0) {}
		ray(const point3& origin, const vec3& direction,const int bc): orig(origin),dir(direction),bounce_count(bc)  {}

		point3 origin() const { return orig; }
		vec3 direction() const { return dir; }

		point3 at(double t) const {return orig + dir * t;}

		int get_bounce_count() const { return bounce_count; }

	private: 
		vec3 dir;
		point3 orig;
		int bounce_count;

};


#endif
