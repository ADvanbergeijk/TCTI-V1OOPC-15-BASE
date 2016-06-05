#ifndef MUUR_HPP
#define MUUR_HPP
#include "window.hpp"
#include "vector.hpp"
#include "line.hpp"
#include "rectangle.hpp"
#include "drawable.hpp"

class muur : public rectangle {
protected:
	rectangle r1;
	rectangle r2;
	rectangle r3;
	rectangle r4;
	bool fill;
	int interval;
	vector bounce;
	vector size;
	int counter = 0;
public:
	muur(window & w,const vector p_start,const vector p_end,vector p_size, bool p_fill, int p_interval,vector p_bounce):
	rectangle(w,p_start,p_end,p_size,p_bounce),
	r1(w,p_start,p_end,p_size,p_bounce),
	r2(w,(p_start + vector(1,1)),(p_end- vector(1,1)),p_size,p_bounce),
	r3(w,(p_start + vector(2,2)),(p_end- vector(2,2)),p_size,p_bounce),
	r4(w,(p_start + vector(3,3)),(p_end- vector(3,3)),p_size,p_bounce),
	fill(p_fill),
	size(p_size),
	interval(p_interval),
	bounce(p_bounce)
   {}
	void update() override;
};	
#endif // MUUR_HPP