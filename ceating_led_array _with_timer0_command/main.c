// timer0 ile led dizisi oluþturma
#include <16F877A.h>
#include <stdlib.h>
#include <math.h>
#FUSES NOWDT,HS,NODEBUG,NOBROWNOUT,NOLVP
#use delay(clock=20M)

#use fast_io(d)

#define led0 pin_d0
#define led1 pin_d1
#define led2 pin_d2
#define led3 pin_d3

#define led4 pin_d4
#define led5 pin_d5
#define led6 pin_d6
#define led7 pin_d7

int i;
int sure;

#int_timer0
void interrupt()
{
 set_timer0(100);
 
 
 for(i=0;i<=7;i++)
 {
 set_timer0(100);
 
 
 output_toggle(led7);
 delay_ms(500);
 output_toggle(led0);
 delay_ms(800);
 
 output_toggle(led6);
 delay_ms(500);
 output_toggle(led1);
 delay_ms(800);
 
 output_toggle(led5);
 delay_ms(500);
 output_toggle(led2);
 delay_ms(800);
 
 output_toggle(led4);
 delay_ms(500);
 output_toggle(led3);
 delay_ms(800);
 }

}

void main()
{

 set_tris_d(0x00);
 output_d(0x00);
 
 setup_timer_0(RTCC_INTERNAL|RTCC_DIV_128);
 enable_interrupts(INT_TIMER0);
 enable_interrupts(GLOBAL);
 
 set_timer0(100);
 
 while(1)
 {
 
 interrupt();
 
 if(sure==360)
 {
 sure=0;
 }
 }
}
 
 
 
 
