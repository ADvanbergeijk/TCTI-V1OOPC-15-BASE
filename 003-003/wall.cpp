#include "wall.hpp"
#include "rectangle.hpp"

wall::wall(window & w, const vector & start, const vector & end , int update_int,const vector& stuiter):
drawable(w,start,end,stuiter),
rec(w,vector(start.x,start.y),vector(end.x,end.y)),

update_interval(update_int)
{}

void wall::update(){
if (update_count < update_interval){
    update_count +=1;
}
else{
    filled = (! filled );
    update_count =1;
}
}
 void wall::draw(){
if (filled==1)
{
   
rec.draw_full();


}
else{
     rec.draw();

 

}
 }





