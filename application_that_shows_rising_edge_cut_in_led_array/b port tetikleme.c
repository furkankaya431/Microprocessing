// B portu deðiþiklik kesmesini (INT_RB) ayarlayarak B portunun hangi pininden yükselen kenar kesme geldiðini led dizisinde gösteren uygulama 
// RB4 kesmesi için RD4 ledi, RB5 kesmesi için RD5 ledi
#include <16f877a.h>
#FUSES HS,NOWDT,NODEBUG,NOLVP,NOPROTECT
#use delay(clock=20M)

#define led4 pin_d4
#define led5 pin_d5
#define led6 pin_d6
#define led7 pin_d7

#int_rb
void rb_kesmesi()
{
 delay_ms(1);
 if(input(pin_b4)) {output_high(led4);delay_ms(2000);}
 if(input(pin_b5)) {output_high(led5);delay_ms(2000);}
 if(input(pin_b6)) {output_high(led6);delay_ms(2000);}
 if(input(pin_b7)) {output_high(led7);delay_ms(2000);}
 

  output_d(0x00);
 
}
void main()
{

 set_tris_b(0xF0);
 set_tris_d(0x00);
 output_d(0x00);
 
 
 enable_interrupts(INT_RB);
 enable_interrupts(GLOBAL);
 
 while(1);
}
