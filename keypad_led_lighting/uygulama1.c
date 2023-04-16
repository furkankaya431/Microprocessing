// keypad ile led yakma uygulaması seven segment
#include <16F877A.h>
#fuses HS,NOWDT
#use delay(clock=20M)

#define sutun1 pin_b7
#define sutun2 pin_b6
#define sutun3 pin_b5
#define sutun4 pin_b4

#define satir1 pin_b3
#define satir2 pin_b2
#define satir3 pin_b1
#define satir4 pin_b0

#define  disp1 pin_c0
#define  disp2 pin_c1
#define  disp3 pin_c2
#define  disp4 pin_c4


void keypad_oku()
{
  
 set_tris_c(0b11101000);
 
 output_c(0x01);
 output_high(disp1);
 delay_ms(20);
 
 output_c(0x02);
 output_high(disp2);
 delay_ms(20);
 
 output_c(0x04);
 output_high(disp3);
 delay_ms(20);
 
 output_c(0x10);
 output_high(disp4);
 delay_ms(20);
 
}
void main()
{
 set_tris_d(0x00);
 set_tris_b(0x0F);
 
 int sayma=0;
 
 while(1)
 {
 
 int cikis1,cikis2,cikis3,cikis4;
 
 output_d(0x00);
 
 output_high(sutun1);
 if(input(satir1)) {output_d(0x60);}
 else if(input(satir2)) {output_d(0x66);}
 else if(input(satir3)) {output_d(0xE0);}
 else if(input(satir4)) {output_d(0x9E);}
  output_low(sutun1);
 
 output_high(sutun2);
 if(input(satir1)) {output_d(0xDA);}
 else if(input(satir2)) {output_d(0xB6);}
 else if(input(satir3)) {output_d(0xFE);}
 else if(input(satir4)) {output_d(0xFC);}
  output_low(sutun2);
 
 output_high(sutun3);
 if(input(satir1)) {output_d(0xF2);}
 else if(input(satir2)) {output_d(0xBE);}
 else if(input(satir3)) {output_d(0xF6);}
 else if(input(satir4)) {output_d(0x8E);}
  output_low(sutun3);
 
 output_high(sutun4);
 if(input(satir1))      {output_d(0xEE);}
 else if(input(satir2)) {output_d(0x3E);}
 else if(input(satir3)) {output_d(0x9C);}
 else if(input(satir4)) {output_d(0x7A);}
 output_low(sutun4);


 if(input(cikis1) && input(cikis2) && input(cikis3) && input(cikis4) )
 {
 if(sayma==0) {cikis4=input_d();sayma++;}
 else if(sayma==1) {cikis3=input_d();sayma++;}
 else if(sayma==2) {cikis2=input_d();sayma++;}
 else if(sayma==3) {cikis1=input_d();sayma++;}
 
 if(sayma==4) {sayma=0;}
 }
 
 keypad_oku();
 delay_ms(35);
 }
}
 

 
 
  


 





 
