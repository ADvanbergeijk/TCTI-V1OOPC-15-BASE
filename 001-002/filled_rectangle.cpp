#include "filled_rectangle.hpp"

//class filled_rectangle{



void filled_rectangle::plot(){
	int y_lengte  = end_y - start_y;
	int x_breedte	=	end_x - start_x;
   int i,j= 0;
   for(i=0;i<y_lengte;i++){
    for(j=0;j<x_breedte;j++){
        w.draw(i + start_x,j + start_y);
    }
   }
   
}
