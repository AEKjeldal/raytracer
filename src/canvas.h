#ifndef CANVAS_H
#define CANVAS_H
#include "vec3.h"
#include <iostream>
#include "common.h"



/* using color=vec3; */
class color: public vec3
{
	public:

		color() : vec3{0,0,0},writeConter(0) {}
		color(double e1,double e2,double e3) : vec3{e1,e2,e3},writeConter(0) {}

		color& operator+=(const color &v) {
			writeConter ++;
			e[0] += v.e[0];
			e[1] += v.e[1];
			e[2] += v.e[2];

			return *this;
		}

		color& operator = (const color &v) {
			writeConter = 1;
			e[0] = v.e[0];
			e[1] = v.e[1];
			e[2] = v.e[2];

			return *this;
		}

		color operator-() const{ 
			return color(-e[0],-e[1],-e[2]); 
		}

		color& operator*=(double t) {
			e[0] *= t;
			e[1] *= t;
			e[2] *= t;

			return *this;
		}


		color& operator/=(double t) {
			return *this /= 1/t;
		}


		int get_writes() const { return writeConter; };

	private:
		int writeConter;


};



class canvas {

	public:
		canvas(int width_px, double aspect_ratio);
		void set_color(const int x,const int y,const color pixel);
		void write_image(std::ostream &out);



		int get_width();
		int get_height();

		void set_width(int w);
		void set_height(int h);



	private:
		int width;
		int height;
		double aspect_ratio;

		void resize();
		std::vector<std::vector<color>> canvas_ptr;
		/* color* canvas_ptr=NULL; */
};










#endif
