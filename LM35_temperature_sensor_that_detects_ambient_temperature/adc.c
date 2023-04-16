// LM35 s.cakl.k sensoru ortam sıcaklığına gore bir gerilim oluşturur. 
//Bu gerilimin RA0 pinine uygulandığını varsayarak bu pinden okuduğu analog veriyi  turunden sicaklik değerine dönüştüren uygulamayı yazınız.
#include <16f877a.h>
#device ADC=11
#fuses HS,NOWDT,NOLVP,NODEBUG,NOPROTECT
#use delay(clock=20M)

#use fast_io(a)
#use fast_io(c)
#use fast_io(d)


#define LCD_ENABLE_PIN PIN_C2 
#define LCD_RS_PIN PIN_C0 
#define LCD_RW_PIN PIN_C1 
#define LCD_DATA4 PIN_D4 
#define LCD_DATA5 PIN_D5 
#define LCD_DATA6 PIN_D6 
#define LCD_DATA7 PIN_D7 

#include <lcd.c>
unsigned long int bilgi;
float voltaj,sicaklik;

void main()
{

setup_psp(PSP_DISABLED) ; 
setup_spi(SPI_SS_DISABLED) ; 
setup_timer_1(T1_DISABLED) ;
setup_timer_2(T2_DISABLED,0,1) ;
setup_CCP1(CCP_OFF);
setup_CCP2(CCP_OFF);

 set_tris_a(0x01);
 set_tris_c(0x00);
 set_tris_d(0x00);
 
 enable_interrupts(INT_AD);
 enable_interrupts(GLOBAL);
 
 setup_adc(adc_clock_div_32);
 setup_adc_ports(AN0_VREF_VREF);
 lcd_init();
 
 set_adc_channel(0);
 
 delay_us(20);
 
 printf(lcd_putc,"\fSicaklik=");
  
  while(1)
  {
   bilgi=read_adc();
   
   voltaj=(0.000488281*bilgi)*1000;
     
   sicaklik=voltaj+2;
   
   lcd_gotoxy(10,1);
   printf(lcd_putc,"%5.1f'C",sicaklik);
   
   delay_ms(100); } 
   
}

