#ifndef VIEWPORT_H
#define VIEWPORT_H
#include "vec3.h"
#include "canvas.h"
/* #include "ray.h"  not yet*/


class viewport {
 public:
	 viewport(double viewport_height,double focal_length,canvas image);
 private:

	 double viewport_height;
	 double focal_point;

	 double px_du;
	 double px_dv;

};

#endif
