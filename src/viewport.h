#ifndef VIEWPORT_H
#define VIEWPORT_H

#include "common.h"

// related to image
#include "canvas.h"

// related to objects
#include "sphere.h"
#include "hittable_lits.h"







class viewport {
 public:
	 viewport(double viewport_height,double focal_length,vec3 camera_position,canvas image);
	 void build();
	 canvas img;
 private:

	 double height;
	 double l_focal;

	 vec3 viewport_start;
	 vec3 camera_pos;

	 vec3 px_du;
	 vec3 px_dv;
};

#endif
