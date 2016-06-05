#include "filled_rectangle.hpp"

//class filled_rectangle{



void filled_rectangle::plot(){
	int y_lengte  = end_y - start_y;
	int x_breedte	=	end_x - start_x;
   int i,j= 0;
   for(i=0;i<x_breedte;i++){
    for(j=0;j<y_lengte;j++){
        w.draw(i + start_x,j + start_y);
    }
   }
   
}
