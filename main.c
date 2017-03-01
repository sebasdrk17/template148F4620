#include <18F4620.h>
#fuses INTRC_IO, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=32000000)

void main (void){
   setup_oscillator(OSC_32MHZ);
   set_tris_D(0x00);
   while(1){
      
   }
}	