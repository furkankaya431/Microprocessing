// sirali led yakip sondurme
#include <16F877A.h>
#FUSES NOWDT,HS
#use delay(clock=20M)

void main() 
{
 int a;
 int i;
 
 set_tris_d(0x00);
 output_d(0x00);
 
 start:
 
 a=128;
 
 for(i=0;i<8;i++) 
 {
 
 output_d(a);
 a=a>>1;  
 delay_ms(250);
 
 }
 
 
 goto start;
 
 
}
   
   
 
 
