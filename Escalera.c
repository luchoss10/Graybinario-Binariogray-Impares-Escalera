#include <16f887.h>                   
#FUSES NOWDT, NOPUT, INTRC_IO, NOPROTECT, NOBROWNOUT, NOWRT
#use delay (internal=8M)

int var1=0, i =1;
void main(){
   set_tris_d(0x00);
   output_d(0);
   
   while(true){
         var1=(var1+i);
         output_d(var1);
         delay_ms(500);
         i=i*2;
         if(var1==255){
            i=1;
            var1=0;
         }
   }
}
