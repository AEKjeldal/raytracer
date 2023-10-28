#include <iostream>
#include "vec3.h"


using color=vec3;
void write_image(std::ostream &out, color pixel)
{
	out << static_cast<int>(255.999*pixel.x())<<' '
	    << static_cast<int>(255.999*pixel.y())<<' '
	    << static_cast<int>(255.999*pixel.z())<<'\n';
}



int main() {
	//Image
	int image_width = 255;
	int image_height = 255;



	std::cout<<"P3\n"<<image_width<< ' ' <<image_height<< "\n255\n";

	for (int h=0; h < image_height; h++)
	{
		std::clog<<"\rRemaining Lines: "<<(image_height-h)<<std::flush;
		for(int w=0; w < image_width;w++)
		{
			auto pixel = color(0,double(h)/(image_height-1),double(w)/(image_width-1));
			write_image(std::cout,  pixel);
		}
	}
	std::clog<<"\rDone                             \n";


}
