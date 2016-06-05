/*
 * Opdracht 6 was zo onduidelijk dat ik ook maar een HEEL Belgische versie heb gemaakt. 
 * Punt 1: Waar heb je de inverse decorator voor nodig?
 * Punt 2: Wat is de al bestaande decorator?
 * Punt 3: Wat moet de inverse decorator decoreren?
*/
#include "hwlib.hpp"

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
   while(1){
		led0.set( 1 );led1.set( 1 );led2.set( 1 );led3.set( 1 ); hwlib::wait_ms( 200 ); led0.set( 0 );led1.set( 0 );led2.set( 0 );led3.set( 0 );
		led4.set( 1 );led5.set( 1 );led6.set( 1 );led7.set( 1 ); hwlib::wait_ms( 200 ); led4.set( 0 );led5.set( 0 );led6.set( 0 );led7.set( 0 );
   }
}
