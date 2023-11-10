#include <iostream>
#include "vec3.h"
#include "ray.h"
#include "canvas.h"
#include "viewport.h"

#include "sphere.h"

using color=vec3;


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





	canvas image = canvas(image_width,aspect_ratio);
	viewport vp  = viewport(2.0,1.0,point3(0,0,0),image);


	// build world
	






	vp.build();
	std::clog<<"\rWriting Image                             \n";
	vp.img.write_image(std::cout);
	std::clog<<"\rDone                             \n";


}
