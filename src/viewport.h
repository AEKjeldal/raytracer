#ifndef VIEWPORT_H
#define VIEWPORT_H
#include "vec3.h"
#include "canvas.h"
/* #include "ray.h"  not yet*/


class viewport {
 public:
	 viewport(double viewport_height,double focal_length,vec3 camera_position,canvas image);
 private:

	 double height;
	 double l_focal;

	 vec3 viewport_start;
	 vec3 camera_pos;

	 vec3 px_du;
	 vec3 px_dv;

	 canvas img;
};

#endif
