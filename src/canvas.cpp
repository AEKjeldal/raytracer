#include "canvas.h"
#include "vec3.h"
#include <cstddef>
#include <ostream>



canvas::canvas(int width_px,double aspect_ratio)
{
	width = (width_px < 1) ? 1 : width_px;


	height = static_cast<int>(width/aspect_ratio);
	height = (height < 1) ? 1 : height; 

	/* canvas_ptr = new color[width*height]; */
	resize();
}



void canvas::resize()
{
	canvas_ptr.resize(height,std::vector<color>(width));
}

int canvas::get_width()
{
	resize();
	return width;
}

int canvas::get_height()
{
	resize();
	return height;
}

canvas canvas::set_height(int h)
{
	
	height = h;
	return *this;
}


canvas canvas::set_width(int w)
{
	
	width = w;
	return *this;
}


void canvas::set_color(const int col,const int row,const color pixel)
{
	canvas_ptr[row][col] = pixel;
}


void canvas::write_image(std::ostream &out)
{
	std::cout<<"P3\n"<<width<< ' ' <<height<< "\n255\n";
	for (int row=0; row<height; row++)
	{
		size_t row_offset = width*row;
		for(size_t col=0; col<width;col++)
		{
		out << static_cast<int>(255.999*canvas_ptr[row][col].x())<<' '
			<< static_cast<int>(255.999*canvas_ptr[row][col].y())<<' '
			<< static_cast<int>(255.999*canvas_ptr[row][col].z())<<'\n';
		}
	}
}




