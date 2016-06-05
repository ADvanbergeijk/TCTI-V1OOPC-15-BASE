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
	int counter = 0;
public:
	muur(window & w,const vector p_start,const vector p_end, bool p_fill, int p_interval):
	rectangle(w,p_start,p_end),
	r1(w,p_start,p_end),
	r2(w,(p_start + vector(1,1)),(p_end- vector(1,1))),
	r3(w,(p_start + vector(2,2)),(p_end- vector(2,2))),
	r4(w,(p_start + vector(3,3)),(p_end- vector(3,3))),
	fill(p_fill),
	interval(p_interval)
   {}
	void update() override;
};	
#endif // MUUR_HPP