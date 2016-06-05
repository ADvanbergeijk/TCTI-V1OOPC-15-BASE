#ifndef VICTIM_HPP
#define VICTIM_HPP



#include "window.hpp"
#include "drawable.hpp"
#include "vector.hpp"
#include "line.hpp"
#include "rectangle.hpp"
class victim :public drawable{

protected :
    bool hit = 0;
 
   int update_count =0;
    rectangle eddard;
    vector start;
    vector end; 


public :
victim(window & w, vector  start, vector  end );

    void draw()override;
    void update()override;
    void interact(drawable & other, drawable * objects[] )override;
};
#endif 