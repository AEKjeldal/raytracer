#include "viewport.h"
#include "ray.h"
#include "vec3.h"
#include "canvas.h"
#include <iostream>


using color=vec3;

double hit_sphere(const point3& center,double radius,const ray& r)
{
	vec3 oc = r.origin()-center;
	// quadratic formula 
	auto a = dot(r.direction(),r.direction());
	auto b = 2.0* dot(oc,r.direction());
	auto c = dot(oc,oc) - radius*radius;
	auto discriminant = b*b -4*a*c;

	if (discriminant < 0)
	{
		return -1.0;
	}
	else{
		return (-b-sqrt(discriminant)) / (2.0*a);
	}

	return (discriminant >=0);
}

color ray_color(const ray& r)
{
	auto t = hit_sphere(point3(0,0,-1), 0.5, r);
	if(t > 0.0)
	{
		vec3 n = unit_vector(r.at(t)-vec3(0,0,-1));
		return 0.5*color(n.x() + 1,n.y()+1,n.z()+1);
	}


	vec3 unit_direction = unit_vector(r.direction());
	auto a = 0.5*(unit_direction.y()+ 1.0);

	return (1.0-a) *color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0);
}


viewport::viewport(double viewport_height,double focal_length,vec3 camera_position,canvas image):camera_pos(camera_position),img(image)
{
	height  = viewport_height;
	l_focal = focal_length;
	
	auto viewport_width  = viewport_height * (static_cast<double>(img.width)/img.height);

	auto viewport_u = vec3(viewport_width,0,0);
	auto viewport_v = vec3(0,-viewport_height,0);

	px_du = viewport_u/img.width;
	px_dv = viewport_v/img.height;

	viewport_start = camera_position - vec3(0,0,focal_length)-viewport_u/2-viewport_v/2;
}


void viewport::build()
{
	vec3 px_start_pos = viewport_start + 0.5 * (px_du-px_dv);

	for(size_t row=0;row<img.height;row++)
	{
		std::clog<<"\rRemaining Lines: "<<(img.height-row)<<std::flush;
		for(size_t col=0;col<img.width;col++)
		{
			auto px_center = px_start_pos + (col * px_du) + (row* px_dv);

			auto ray_direction = px_center - camera_pos;
			
			ray r(camera_pos,ray_direction);
			img.set_color(col, row, ray_color(r));

		}
	}
}


