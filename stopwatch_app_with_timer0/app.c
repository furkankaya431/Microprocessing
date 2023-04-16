// timer0 ile kronometre uygulamasý
#include <16F877A.h>
#include <stdlib.h>
#include <math.h>
#fuses XT,NOWDT,NODEBUG,NOBROWNOUT,NOPROTECT,NOLVP
#use delay(clock=4M)

#use fast_io(d)
#use fast_io(c)
#use fast_io(b)

int32 s_birler=0, s_onlar=0, time=0, s=0, d=0, d_birler=0, d_onlar=0, sayac=0;

#int_timer0
void timer0_kesmesi()
{

   sayac++;
   if(sayac==60) {time++;sayac=0;}
   
   s=time%60;
   s_birler=s%10;
   s_onlar=s/10;
   
   d=time/60;
   d_birler=d%10;
   d_onlar=d/10;
   
   set_timer0(217);
}
   
 
#define  disp1 pin_c4
#define  disp2 pin_c2
#define  disp3 pin_c1
#define  disp4 pin_c0

void main()
{
 delay_ms(1000);
 setup_timer_0(RTCC_INTERNAL|RTCC_DIV_256);
 enable_interrupts(INT_TIMER0);
 enable_interrupts(GLOBAL);
 
 int digit[10]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
 
 set_tris_c(0x00);
 set_tris_d(0x00);
 set_tris_b(0x01);
 
 output_high(disp1);
 output_high(disp2);
 output_high(disp3);
 output_high(disp4);
 
 set_timer0(217);
 
 while(1)
 {
 
 output_high(disp1);
 output_low(disp2);
 output_low(disp3);
 output_low(disp4);
 output_d(digit[d_onlar]);
 delay_ms(5);
 
 output_high(disp2);
 output_low(disp1);
 output_low(disp3);
 output_low(disp4);
 output_d(digit[d_birler]);
 delay_ms(5);
 
 output_high(disp3);
 output_low(disp1);
 output_low(disp2);
 output_low(disp4);
 output_d(digit[s_onlar]);
 delay_ms(5);
 
 output_high(disp4);
 output_low(disp2);
 output_low(disp3);
 output_low(disp1);
 output_d(digit[s_birler]);
 delay_ms(5);
 
 if(input(pin_b0)) {delay_ms(10);time=0;}
 
 }
 
}


 
 
  

