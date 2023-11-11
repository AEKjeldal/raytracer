#ifndef CANVAS_H
#define CANVAS_H
#include "vec3.h"
#include <iostream>
#include "common.h"



using color=vec3;

class canvas {

	public:
		canvas(int width_px, double aspect_ratio);
		void set_color(const int x,const int y,const color pixel);
		void write_image(std::ostream &out);



		int get_width();
		int get_height();

		canvas set_width(int w);
		canvas set_height(int h);



	private:
		int width;
		int height;

		void resize();
		std::vector<std::vector<color>> canvas_ptr;
		/* color* canvas_ptr=NULL; */
};



#endif
