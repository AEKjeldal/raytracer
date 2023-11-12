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


	 viewport(double viewport_height,vec3 camera_position,canvas image);


	 void render_scene(const object_container& scene);
	 canvas img;
 private:
	 void initialize();
	 color ray_color(const ray& r, const hittable_object& scene);


	 double height;
	 double width;

	 double l_focal;

	 vec3 px_start_pos;
	 vec3 camera_pos;

	 vec3 px_du;
	 vec3 px_dv;
};

#endif
