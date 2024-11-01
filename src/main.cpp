#include <iostream>
#include <memory>
#include "vec3.h"
#include "ray.h"
#include "canvas.h"
#include "viewport.h"

#include "sphere.h"
#include "hittable_lits.h"

#include <fstream>


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
	viewport vp  = viewport(2.0,point3(0,0,0),image);



	// build world
	object_container scene;
	scene.add(std::make_shared<sphere>(point3(0,0,-1),0.5));
	scene.add(std::make_shared<sphere>(point3(0,-100.5,-1),100));


	std::fstream imageFile("output.bmp",imageFile.out);


	vp.render_scene(scene,100);
	std::clog<<"\rWriting Image                             \n";
	vp.img.write_image(imageFile);
	imageFile.close();
	std::clog<<"\rDone                             \n";


}
