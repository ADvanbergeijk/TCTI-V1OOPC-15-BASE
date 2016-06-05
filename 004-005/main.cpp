#include "hwlib.hpp"

class pin_in_all : public hwlib::pin_in {
private:
//hwlib::target::pin_in * list[ 2 ]; 
hwlib::target::pin_in & p0;
hwlib::target::pin_in & p1;

public:
 pin_in_all(
 hwlib::target::pin_in & p0,
 hwlib::target::pin_in & p1
 ):
p0(p0),
p1(p1)
 {}

 bool get() override{
	return (!(p0.get()) && !(p1.get()));
 }
};

int main(int argc, char **argv)
{
// kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
 namespace target = hwlib::target;
 auto led =  target::pin_out(  target::pins::d3 );
	auto kminder =  target::pin_in( target::pins::d8 );
	auto kmeer =  target::pin_in(  target::pins::d9 );
	led.set(0);
	auto ins = pin_in_all(kminder, kmeer);
	while(1){
		led.set(ins.get());
		hwlib::wait_ms( 2 );
	}
}
