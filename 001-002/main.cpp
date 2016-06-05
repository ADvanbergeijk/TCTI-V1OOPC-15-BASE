#include <stdio.h>
#include <iostream>
#include "window.hpp"
#include "filled_rectangle.hpp"
#include "line.hpp"
#include "circle.hpp"
#include "figure.hpp"

int main(int argc, char **argv)
{
window w( 128, 64, 8 );
	figure fig2(w,40,10,1);
	figure fig(w,10,10,2);
	fig.plot();
	fig2.plot();
	return 0;
}
