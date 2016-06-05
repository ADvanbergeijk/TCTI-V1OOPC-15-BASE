#include "muur.hpp"
void muur::update(){
	r1.draw();
	r4.draw();
	if(fill == true){
	r2.draw();
	r3.draw();		
	}
	if (counter % interval == 0){
	if(fill == false){
	fill = true;
	}
	else{
		fill= false;
	}
	}
	counter ++;
	}