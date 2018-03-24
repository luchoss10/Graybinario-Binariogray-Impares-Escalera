#include <16f887.h>                   
#FUSES NOWDT, NOPUT, INTRC_IO, NOPROTECT, NOBROWNOUT, NOWRT
#use delay (internal=8M)                                                                    

int e;                                                                                     
int1 In0,In1,In2,In3,Out0,Out1,Out2,Out3;// Entradas y salidas.
int8 Dato; // dato de salida.
                                               
void main(){
   set_tris_a(0x1F);
   set_tris_d(0x00);
                       
   output_d(0x00);
   while(true){
      e=input_a();
      if(bit_test(e,4)==1){                              
         In0=INPUT(PIN_A0); //Leo todos los puertos de entrada individualmente.
         In1=INPUT(PIN_A1);
         In2=INPUT(PIN_A2);                 
         In3=INPUT(PIN_A3); 
         //Empiezo a hacer las acciones correspondientes para optener el codigo gray
         Out3=In3; //El ultimo numero de derecha a izquierda se conserva
         Out2=In3^In2; //El  tercer valor de salida corresponde a una XOR entre In3 e In2
         Out1=In2^In1; //El  segundo valor de salida corresponde a una XOR entre In2 e In1
         Out0=In1^In0; //El primer valor de salida corresponde a una XOR entre In1 e In0
         Dato=Out3*8+Out2*4+Out1*2+Out0*1;//Le doy una interpretacion numerica al valor de salida para que sea m�s facil de mostrar
         output_d(Dato); //Muestro el valor obtenido      
      }                                   
      else if(bit_test(e,4)==0){                      
         In0=INPUT(PIN_A0); //Leo todos los puertos de entrada individualmente.
         In1=INPUT(PIN_A1);
         In2=INPUT(PIN_A2);                 
         In3=INPUT(PIN_A3);
         //Empiezo a hacer las acciones correspondientes para optener el codigo gray
         Out3=In3; //El ultimo numero de derecha a izquierda se conserva
         Out2=In3^In2; //El  tercer valor de salida corresponde a una XOR entre In3 e In2
         Out1=Out2^In1; //El  segundo valor de salida corresponde a una XOR entre In2 e In1
         Out0= Out1^In0; //El primer valor de salida corresponde a una XOR entre In1 e In0
         Dato=Out3*8+Out2*4+Out1*2+Out0*1;//Le doy una interpretacion numerica al valor de salida para que sea m�s facil de mostrar
         output_d(Dato); //Muestro el valor obtenido                       
      }                       
   }
}                                                                                         
