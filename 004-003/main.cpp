#include "hwlib.hpp"
void update( hwlib::port_out_from_pins & leds, hwlib::pin_in & knopmeer, hwlib::pin_in & knopminder){
        unsigned int counter = 0;
		while(1){
        if (!knopmeer.get()&& counter < 4){
            counter++;
            leds.set((0x01<<counter)-1);
            hwlib::wait_ms(500);
        }
        if (!knopminder.get()&& counter > 0){
			counter --;
            leds.set((0x01<<counter)-1);
            
					hwlib::wait_ms( 500 );
        }

		}

}

int main( void ){ 
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   // enable the clock to all GPIO
 PMC->PMC_PCER0 = ( 0x3F << 11 ); 
   auto led0 = hwlib::target::pin_out( hwlib::target::pins::d7 );
  auto led1 = hwlib::target::pin_out( hwlib::target::pins::d6 );
  auto led2 = hwlib::target::pin_out( hwlib::target::pins::d5 );
   auto led3 = hwlib::target::pin_out( hwlib::target::pins::d4 );
	auto kminder = hwlib::target::pin_in(hwlib::target::pins::d8 );
	auto kmeer = hwlib::target::pin_in( hwlib::target::pins::d9 );
	led0.set(0);
    led1.set(0);
    led2.set(0);
    led3.set(0);

 auto leds = hwlib::port_out_from_pins( led0, led1, led2, led3 );
 while(1){
            update(leds,kmeer,kminder);
			hwlib::wait_ms( 20 );
    }
}