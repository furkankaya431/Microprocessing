// led yakip sondurme deneyi
#include <16F877A.h>
#FUSES NOWDT,HS,NODEBUG,NOPROTECT,NOCPD,NOLVP
#use delay(clock=20M)


void main () 
{
 set_tris_d(0x00);
while(1)
{
  output_d(0xFF);
  delay_ms(1000);
  output_d(0x00);
  delay_ms(1000);
  
}

}
  

