#include "hwlib.hpp"
void update( hwlib::port_out_from_pins & leds, hwlib::pin_in & knopmeer, hwlib::pin_in & knopminder,hwlib::hc595 & ledc){
        unsigned int counter = 0;
		while(1){
        if (!knopmeer.get()&& counter < 8){
            counter++;
            leds.set((0x01<<counter)-1);
			ledc.set((0x01<<counter)-1);
            hwlib::wait_ms(500);
        }
        if (!knopminder.get()&& counter > 0){
			counter --;
            leds.set((0x01<<counter)-1);
			ledc.set((0x01<<counter)-1);
            
					hwlib::wait_ms( 500 );
        }

		}

}

int main( void ){ 
   // kill the watchdog
   WDT->WDT_MR = WDT_MR_WDDIS;
   // enable the clock to all GPIO
 PMC->PMC_PCER0 = ( 0x3F << 11 ); 
 namespace target = hwlib::target;
 auto ds =  target::pin_out(  target::pins::d12 );
  auto shcp =  target::pin_out(  target::pins::d11 );
 auto stcp =  target::pin_out(  target::pins::d10 );
   auto led0 =  target::pin_out(  target::pins::d7 );
  auto led1 =  target::pin_out(  target::pins::d6 );
  auto led2 =  target::pin_out(  target::pins::d5 );
   auto led3 =  target::pin_out(  target::pins::d4 );
	auto kminder =  target::pin_in( target::pins::d8 );
	auto kmeer =  target::pin_in(  target::pins::d9 );
	led0.set(0);
    led1.set(0);
    led2.set(0);
    led3.set(0);
	 auto spi = hwlib::spi_bus_bit_banged_sclk_mosi_miso(stcp, ds, hwlib::pin_in_dummy );
		auto ledc = hwlib::hc595( spi, shcp );
auto leds =  hwlib::port_out_from_pins( led0, led1, led2, led3 );
 update(leds,kmeer,kminder,ledc);

}