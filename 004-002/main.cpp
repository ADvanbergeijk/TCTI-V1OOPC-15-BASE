#include "hwlib.hpp"
int main( void ){ 
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
   auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
   auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
    int delta = 2;
   int mult = 50;
   int max_s = 10;
   int i;
   for(i = 1; i<=max_s && i > 0; i = i + delta){
      led0.set( 1 ); led1.set ( 1 );hwlib::wait_ms( i*mult ); led0.set( 0 ); led1.set ( 0 ); 
      led1.set( 1 ); led2.set ( 1 );hwlib::wait_ms( i*mult ); led1.set( 0 ); led2.set ( 0 );
      led2.set( 1 ); led3.set ( 1 );hwlib::wait_ms( i*mult ); led2.set( 0 ); led3.set ( 0 );
      led2.set( 1 ); led1.set ( 1 );hwlib::wait_ms( i*mult ); led2.set( 0 );led1.set ( 0 ); 
    if(i == (max_s-1)){
       delta = -2;
    }
    if(i == 1){
        delta = 1;
    }
   }
}