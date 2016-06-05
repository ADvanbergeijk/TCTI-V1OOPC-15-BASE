#include <stdio.h>

#include <iostream>

#include "window.hpp"
#include "filled_rectangle.hpp"

int main(int argc, char **argv){
	window w( 128, 100, 2 );
	filled_rectangle s(w,20, 20, 40, 40);
	filled_rectangle r(w,50, 50, 60 ,100);
	s.plot();
	r.plot();
	return 0;
}

