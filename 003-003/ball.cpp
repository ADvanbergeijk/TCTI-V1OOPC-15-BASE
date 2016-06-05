#include "ball.hpp"
#include <iostream>

void ball::update(){
   location += speed;
}

ball::ball( window & w, const vector & midpoint, int radius, const vector & speed ):
   circle( w, midpoint, radius ),
   speed( speed )
{}

void ball::interact( drawable & other,drawable * objects[] ){
   if( this != & other){
      if( overlaps( other )){
        speed.x *= other.stuiter.x;
        speed.y *= other.stuiter.y;
        }
 
      }
   
   }
