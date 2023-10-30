#ifndef CANVAS_H
#define CANVAS_H
#include "vec3.h"
#include <iostream>



using color=vec3;

class canvas {

	public:
		canvas(int width_px, double aspect_ratio);
		void set_color(const int x,const int y,const color pixel);
		void write_image(std::ostream &out);

		int width;
		int height;
	private:
		color* canvas_ptr=NULL;
};



#endif
