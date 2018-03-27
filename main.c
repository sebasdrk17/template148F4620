#include <18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, NOMCLR, STVREN, NOLVP, NODEBUG
#use delay(clock=16000000)

#define TX_232        PIN_C6
#use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1)
#use fast_io(c)

void main (void){
   setup_oscillator(OSC_16MHZ);
   printf("Hola Mundo\n");//Puedes usar putc o printf. Revisa la documentación de CCS para ver que mas puedes hacer.
   while(1){
      
   }
}	
