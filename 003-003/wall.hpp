#ifndef WALL_HPP
#define WALL_HPP



#include "window.hpp"
#include "drawable.hpp"
#include "vector.hpp"
#include "line.hpp"
#include "rectangle.hpp"
class wall :public drawable{

protected :
    bool filled = 0;
    int update_interval;
    int update_count=1;
    rectangle rec;



public :
wall(window & w, const vector & start, const vector & end , int update_int,const vector & stuiter);

    void draw()override;
    void update();
};
#endif 