#include <iostream>
#include "vec3.h"
#include "ray.h"
#include "canvas.h"
#include "viewport.h"


using color=vec3;

/* double hit_sphere(const point3& center,double radius,const ray& r) */
/* { */
/* 	vec3 oc = r.origin()-center; */
/* 	// quadratic formula  */
/* 	auto a = dot(r.direction(),r.direction()); */
/* 	auto b = 2.0* dot(oc,r.direction()); */
/* 	auto c = dot(oc,oc) - radius*radius; */
/* 	auto discriminant = b*b -4*a*c; */
/*  */
/* 	if (discriminant < 0) */
/* 	{ */
/* 		return -1.0; */
/* 	} */
/* 	else{ */
/* 		return (-b-sqrt(discriminant)) / (2.0*a); */
/* 	} */
/*  */
/* 	return (discriminant >=0); */
/* } */
/*  */
/*  */
/*  */
/* color ray_color(const ray& r) */
/* { */
/* 	auto t = hit_sphere(point3(0,0,-1), 0.5, r); */
/* 	if(t > 0.0) */
/* 	{ */
/* 		vec3 n = unit_vector(r.at(t)-vec3(0,0,-1)); */
/* 		return 0.5*color(n.x() + 1,n.y()+1,n.z()+1); */
/* 	} */
/*  */
/* 	vec3 unit_direction = unit_vector(r.direction()); */
/* 	auto a = 0.5*(unit_direction.y()+ 1.0); */
/*  */
/* 	return (1.0-a) *color(1.0,1.0,1.0) + a*color(0.5,0.7,1.0); */
/* } */
/*  */

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
	/* int image_height = static_cast<int>(image_width/aspect_ratio); */
	/* image_height = (image_height < 1) ? 1 : image_height;  */

	canvas image = canvas(image_width,aspect_ratio);
	viewport vp  = viewport(2.0,1.0,point3(0,0,0),image);
	vp.build();
	std::clog<<"\rWriting Image                             \n";
	image.write_image(std::cout);
	std::clog<<"\rDone                             \n";

	
	// setup camera
	/* auto viewport_height = 2.0; */
	/* auto viewport_width  = viewport_height * (static_cast<double>(image.width)/image.height); */
	/* auto focal_length    = 1.0; */
	/* point3 camera_position = point3(0,0,0); */


	// setup viewport, notice that we are usign image cordinates
	// Refactor this to class 
	/* auto viewport_u = vec3(viewport_width,0,0); */
	/* auto viewport_v = vec3(0,-viewport_height,0); */
	/*  */
	/* vec3 px_du = viewport_u/image.width; */
	/* vec3 px_dv = viewport_v/image.height; */
	/*  */
	/* // viewport start relative to camera position */
	/* vec3 viewport_start		= camera_position - vec3(0,0,focal_length)-viewport_u/2-viewport_v/2; */
	/* vec3 px_start_pos		= viewport_start + 0.5 * (px_du-px_dv); */

	/* std::cout<<"P3\n"<<image_width<< ' ' <<image.width<< "\n255\n"; */
	/* for (int h=0; h < image.height; h++) */
	/* { */
	/* 	std::clog<<"\rRemaining Lines: "<<(image.height-h)<<std::flush; */
	/* 	for(int w=0; w < image.width;w++) */
	/* 	{ */
	/* 		auto px_center = px_start_pos + (w * px_du) + (h* px_dv); */
	/*  */
	/* 		auto ray_direction = px_center - camera_position; */
	/* 		ray r(camera_position,ray_direction); */
	/*  */
	/* 		/* auto pixel = ray_color(r); */ 
	/* 		image.set_color(w, h, ray_color(r)); */
	/*  */
	/* 		/* write_image(std::cout,  pixel); */ 
	/* 	} */
	/* } */


}
