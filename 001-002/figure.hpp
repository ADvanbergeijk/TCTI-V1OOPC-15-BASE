#include "window.hpp"
#include "filled_rectangle.hpp"
#include "line.hpp"
#include "circle.hpp"
class figure{
private:
	int startx;
	int starty;
	int scale;
	filled_rectangle s;
	line line1;
	line line2;
	circle circle1;
	window & w;
public:
	figure(window & w,int p_start_x,int p_start_y,int p_scale):
	w (w),
	scale(p_scale),
	startx( p_start_x ),
	starty( p_start_y ),
	s(w,startx, starty, startx + 20, starty + 20),
	line1(w,startx,starty + 20,startx + 10,starty + 40),
	line2(w,startx + 20,starty + 20,startx + 10,starty + 40),
	circle1(w,startx + 10,starty + 40,5*scale)
{}
	void plot();
};