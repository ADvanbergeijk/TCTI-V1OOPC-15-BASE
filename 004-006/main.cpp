#include "hwlib.hpp"

class pin_out_all : public hwlib::pin_out {
private:
   hwlib::pin_out * list[ 4 ];     
   
public:

   pin_out_all( 
      hwlib::pin_out & p0, 
      hwlib::pin_out & p1 = hwlib::pin_out_dummy,  
      hwlib::pin_out & p2 = hwlib::pin_out_dummy, 
      hwlib::pin_out & p3 = hwlib::pin_out_dummy 
   ):
      list{ &p0, &p1, &p2, &p3 }
   {}
   
   void set( bool v ) override{
      for( auto p  : list ){
          p->set( v );
      }
   }
};

class pin_out_invert{
private:
	pin_out_all set1;
	pin_out_all set2;
public:
	pin_out_invert(hwlib::pin_out & p0, hwlib::pin_out & p1, hwlib::pin_out & p2, hwlib::pin_out & p3, hwlib::pin_out & p4, hwlib::pin_out & p5, hwlib::pin_out & p6, hwlib::pin_out & p7):
	set1(p0, p1, p2, p3),
	set2(p4, p5, p6, p7)
	{}
	
	void kitt(){
		set1.set(1);
		hwlib::wait_ms(200);
		set1.set(0);
		set2.set(1);
		hwlib::wait_ms(200);
		set2.set(0);
	}
};
int main(int argc, char **argv)
{
	   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
 namespace target = hwlib::target;
   auto led0 =  target::pin_out(  target::pins::d2 );
  auto led1 =  target::pin_out(  target::pins::d3 );
  auto led2 =  target::pin_out(  target::pins::d4 );
   auto led3 =  target::pin_out(  target::pins::d5 );
    auto led4 =  target::pin_out(  target::pins::d6 );
  auto led5 =  target::pin_out(  target::pins::d7 );
  auto led6 =  target::pin_out(  target::pins::d8 );
   auto led7 =  target::pin_out(  target::pins::d9 );
	led0.set(0);
    led1.set(0);
    led2.set(0);
    led3.set(0);
	led4.set(0);
    led5.set(0);
    led6.set(0);
    led7.set(0);
	 auto leds = pin_out_invert( led0, led1, led2, led3, led4, led5, led6, led7);
	 while(1){
	leds.kitt();
	 }
}
