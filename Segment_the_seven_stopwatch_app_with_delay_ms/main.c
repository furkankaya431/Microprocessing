// delay_ms ile kronometre uygulamasý seven segment
#include <16F877A.h>
#include <stdlib.h>
#include <math.h>
#fuses HS,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP
#use delay(clock=20M)
#use fast_io(d)
#use fast_io(c)
#use fast_io(b)

void main()
{
set_tris_b(0x0F);
set_tris_d(0x00);
set_tris_c(0b11101000); 
int8 d_birler=0,d_onlar=0,s_birler=0,s_onlar=0,dakika=0,saniye=0;
int32 sure=0,sayac=0;
int digit[10]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
while(1)
{
output_c(0x01);
output_d(digit[s_birler]);
delay_ms(5);

output_c(0x02);
output_d(digit[s_onlar]);
delay_ms(5);

output_c(0x04);
output_d(digit[d_birler]);
delay_ms(5);

output_c(0x10);
output_d(digit[d_onlar]);
delay_ms(5);

sayac--; 
         
if(sayac%10==0)
{
 sure++;
 saniye=sure%60;
 s_birler=saniye%10;
 s_onlar=saniye/10;
 dakika=sure/60;
 d_birler=dakika%10;
 d_onlar=dakika/10;
}
}}
    
   

 
