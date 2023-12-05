#include "canvas.h"
#include "vec3.h"
#include <cstddef>
#include <ostream>



canvas::canvas(int width_px,double aspect_ratio)
{
	width = (width_px < 1) ? 1 : width_px;

	height = static_cast<int>(width/aspect_ratio);
	height = (height < 1) ? 1 : height; 

	resize();
}



void canvas::resize()
{
	canvas_ptr.resize(height,std::vector<color>(width));
}

int canvas::get_width()
{
	return width;
}

int canvas::get_height()
{
	return height;
}

void canvas::set_height(int h)
{
	height = (h < 1) ? 1 : h; 
	resize();
}


void canvas::set_width(int w)
{
	width = (w < 1) ? 1 : w;
	resize();
}


void canvas::set_color(const int col,const int row,const color pixel)
{
	canvas_ptr[row][col] += pixel;
}


void canvas::write_image(std::ostream &out)
{
	std::cout<<"P3\n"<<width<< ' ' <<height<< "\n255\n";
	for (int row=0; row<height; row++)
	{
		size_t row_offset = width*row;
		for(size_t col=0; col<width;col++)
		{

		auto pixel = canvas_ptr[row][col];
		out << static_cast<int>(255.999*pixel.x()/pixel.get_writes())<<' '
			<< static_cast<int>(255.999*pixel.y()/pixel.get_writes())<<' '
			<< static_cast<int>(255.999*pixel.z()/pixel.get_writes())<<'\n';
		}
	}
}

