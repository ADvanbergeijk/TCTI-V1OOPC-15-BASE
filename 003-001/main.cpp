#include "window.hpp"
#include "line.hpp"
#include "ball.hpp"
#include "rectangle.hpp"
#include "muur.hpp"

int main(){
   window w( vector( 128, 64 ), 4 );
//   line top( w, vector(   0,  0 ), vector( 127,  0 ) );
//   line right( w, vector( 127,  0 ), vector( 127, 63 ) );
//   line bottom( w, vector( 127, 63 ), vector(   0, 63 ) );
//   line left( w, vector(   0, 63 ), vector(   0,  0 ) );
   ball b( w, vector( 10, 10 ), 8, vector( 2, 2 ) );
   muur boven(w,vector (0,4),vector(128,60),false,5);
   
   drawable * objects[] = { &b, &boven};

   for(;;){
      w.clear();
      for( auto & p : objects ){
         p->draw();
      }
      wait_ms( 30 );
      for( auto & p : objects ){
          p->update();
      }
   }
}

