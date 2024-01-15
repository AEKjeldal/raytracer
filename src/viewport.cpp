#include "viewport.h"
#include "common.h"
#include "hittable.h"
#include "ray.h"
#include "vec3.h"
#include "canvas.h"
#include <cmath>
#include <iostream>



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

color viewport::ray_color(const ray& r, const hittable_object& scene)
{
	hit_record rec; 
	if(scene.hit(r,0,infinity,rec))
	{
		vec3 direction = random_on_hemisphere(rec.normal);
		return 0.5 * ray_color(ray(rec.p,direction),scene);
	}

	vec3 unit_direction = unit_vector(r.direction());
	auto a = 0.5*(unit_direction.y()+ 1.0);

	return (1.0-a) *color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0);
}


viewport::viewport(double viewport_height,vec3 camera_position,canvas image):camera_pos(camera_position),img(image) { }

void viewport::initialize()
{

	height  = 2.0;
	auto focal_length = 1.0;

	l_focal = focal_length;
	
	width  = height * (static_cast<double>(img.get_width())/img.get_height());

	auto viewport_u = vec3(width,0,0);
	auto viewport_v = vec3(0,-height,0);

	px_du = viewport_u/img.get_width();
	px_dv = viewport_v/img.get_height();

	auto viewport_start = camera_pos - vec3(0,0,focal_length)-viewport_u/2-viewport_v/2;
	px_start_pos = viewport_start + 0.5 * (px_du-px_dv);
}



void viewport::render_scene(const object_container& scene,int samples)
{

	initialize();
	std::clog<<"\rRemaining Lines: "<<img.get_height()<<std::flush;
	for(size_t row=0;row<img.get_height();row++)
	{
		for(size_t col=0;col<img.get_width();col++)
		{
			// auto px_center = px_start_pos + (col * px_du) + (row* px_dv);

			// auto ray_direction = px_center - camera_pos;
			
			for (int i=0; i < samples; i++)
			{
				ray r = get_ray(col,row);
				img.set_color(col, row, ray_color(r,scene));
			}
		}
	}
}

ray viewport::get_ray(int x, int y)
{
	auto p_center = px_start_pos + (x * px_du) + (y * px_dv);
	auto p_sample = p_center + pixel_sample_square();

	auto ray_orig = camera_pos;
	auto ray_direction = p_sample - ray_orig;

	return ray(ray_orig,ray_direction);
}



vec3 viewport::pixel_sample_square()
{
	auto px = -0.5 + random_double();
	auto py = -0.5 + random_double();
	return (px * px_du) + (py  * px_dv);
}


















