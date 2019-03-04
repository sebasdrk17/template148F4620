#include<library/18F4620.h>
#fuses HS, NOFCMEN, NOIESO, PUT, NOBROWNOUT, NOWDT
#fuses NOPBADEN, STVREN, NOLVP, NODEBUG /*NOMCLR, Se quito de aqui para aplicar el resed al Micro*/
#use delay(clock=16000000)

#define __DEBUG_SERIAL__ //Si comentas esta linea se deshabilita el debug por serial y el PIN_C6 puede ser usado en forma digital I/O

#ifdef __DEBUG_SERIAL__
   #define TX_232 PIN_C6
   #use RS232(BAUD=9600, XMIT=TX_232, BITS=8,PARITY=N, STOP=1)
   #use fast_io(c)
#endif

void contAnillo();
void main (void){
   setup_oscillator(OSC_16MHZ);
   set_tris_c(0x00); //Ponemos todos los bits en 0, ya que seran de salida para los leds
#ifdef __DEBUG_SERIAL__ //Deberiamos de proteger nuestras depuraciones de esta forma o usar una macro ya protegida.
   printf("Hola Mundo\n");//Puedes usar putc o printf. Revisa la documentación de CCS para ver que mas puedes hacer.
#endif
   while(1){
       contAnillo();
       delay_ms(500); //Hacemos un retraso de 500ms para poder observar el desplazamiento de los bits
   }
}

void contAnillo(){
    int count=0b10000000; //Hacemos un contador el cual sera nuestra base para el valor de salida
    output_c(count); //count representa el byte de salida del puerto, (256 = puerto 7 / 128= puerto 6)
       count/=2; //Se divide entre 2 para llevar el conteo exacto del puerto (10000000(Prto 7)-01000000-64(Prto5) etc)
       if(count==0){ //Si (el contador es igual a 0) es decir llega al LSB
           count=0b10000000; //El contador sera 256 de nuevo osea el MSB
       }
}
