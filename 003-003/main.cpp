#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "wall.hpp"
#include "victim.hpp"
int main(){
   window w( vector( 128, 64 ),2 );
    
  wall top (w, vector (0,0), vector(127,4),2,vector(1,-1));
  wall left(w,vector(0,0),vector(4,127),2,vector(-1,1));
  wall right(w,vector(124,0),vector(127,63),2,vector(-1,1));
  wall bottom(w,vector(0,59),vector(127,63),2,vector(1,-1));
   ball b( w, vector( 50, 20 ), 9, vector( 5, 2 ) );
 victim v(w, vector(20,20), vector(30,40));
  victim r(w, vector(100,20), vector(110,40));
   drawable * objects[] = { &b ,&v,&r,&top, &left, &right, &bottom};

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
   wait_ms( 10);
      for( auto & p : objects ){
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other, objects );
         } 
      }
   }
}

