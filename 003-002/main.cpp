#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "rectangle.hpp"
#include "muur.hpp"

int main(){
   window w( vector( 128, 64 ), 4);
   ball b( w, vector( 70, 30 ), 9, vector( 5, 2 ) );
   line test(w,vector (128,0),vector(128,64));
	muur boven(w,vector (0,0),vector(128,4), vector (128,0), false,5,vector (1,-1));
	muur rechts(w,vector (124,0),vector(128,64), vector (4,64), false,5,vector (-1,1));
	muur links(w,vector (0,0),vector(4,64), vector (0,64), false,5,vector (-1,1));
	muur onder(w,vector (0,60),vector(128,64), vector (128,0),false,5,vector (1,-1));
   
   drawable * objects[] = { &b,&boven,&rechts,&links,&onder};

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 100);
      for( auto & p : objects ){
          p->update();
      }
      for( auto & p : objects ){
         for( auto & other : objects ){
            p->interact( *other );
         } 
      }
   }
}

