#ifndef RAY_H
#define RAY_H

#include "vec3.h"



class ray {

	// Constructors
	ray() {}
    // initialize  orig and dir with provided values
	ray(const point3& origin, const vec3& direction): orig(origin),dir(direction) {}


	point3 origin() const { return orig; }
	vec3 direction() const { return dir; }

	point3 at(double t) const {return orig + dir * t;}

	private: 
		vec3 dir;
		point3 orig;
};


#endif