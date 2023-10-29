#include <iostream>
#include "vec3.h"
#include "ray.h"


using color=vec3;

bool hit_sphere(const point3& center,double radius,const ray& r)
{
	vec3 oc = r.origin()-center;
	// quadratic formula 
	auto a = dot(r.direction(),r.direction());
	auto b = 2.0* dot(oc,r.direction());
	auto c = dot(oc,oc) - radius*radius;
	auto discriminant = b*b -4*a*c;
	return (discriminant >=0);
}



color ray_color(const ray& r)
{
	if(hit_sphere(point3(0,0,-1), 0.5, r))
	{
		return color(1,0,0);
	}

	vec3 unit_direction = unit_vector(r.direction());
	auto a = 0.5*(unit_direction.y()+ 1.0);

	return (1.0-a) *color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0);
}


void write_image(std::ostream &out, color pixel)
{
	out << static_cast<int>(255.999*pixel.x())<<' '
	    << static_cast<int>(255.999*pixel.y())<<' '
	    << static_cast<int>(255.999*pixel.z())<<'\n';
}



int main() {
	//Setup image
	auto aspect_ratio = 16/9.0;
	int image_width = 400;

	// set image height (must be at least 1 pixel)
	int image_height = static_cast<int>(image_width/aspect_ratio);
	image_height = (image_height < 1) ? 1 : image_height; 

	
	// setup camera
	auto viewport_height = 2.0;
	auto viewport_width  = viewport_height * (static_cast<double>(image_width)/image_height);
	auto focal_length    = 1.0;
	point3 camera_position = point3(0,0,0);


	// setup viewport, notice that we are usign image cordinates
	// Refactor this to class 
	auto viewport_u = vec3(viewport_width,0,0);
	auto viewport_v = vec3(0,-viewport_height,0);

	auto px_du = viewport_u/image_width;
	auto px_dv = viewport_v/image_height;

	// viewport start relative to camera position
	auto viewport_start		= camera_position - vec3(0,0,focal_length)-viewport_u/2-viewport_v/2;
	auto px_start_pos		= viewport_start + 0.5 * (px_du-px_dv);



	std::cout<<"P3\n"<<image_width<< ' ' <<image_height<< "\n255\n";

	for (int h=0; h < image_height; h++)
	{
		std::clog<<"\rRemaining Lines: "<<(image_height-h)<<std::flush;
		for(int w=0; w < image_width;w++)
		{
			auto px_center = px_start_pos + (w * px_du) + (h* px_dv);

			auto ray_direction = px_center - camera_position;
			ray r(camera_position,ray_direction);

			auto pixel = ray_color(r);
			write_image(std::cout,  pixel);
		}
	}
	std::clog<<"\rDone                             \n";


}
