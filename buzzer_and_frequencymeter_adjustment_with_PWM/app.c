// Program çalýþtýrýldýðýnda %50 lik doluluk oraný, 2000 Hz’lik frekans ile çalýþmaya baþlayan ve 2 adet butonla doluluk oraný %5’lik deðiþimlerle arttýrýlabilen ve azaltýlabilen,
// diðer 2 adet butonla PWM frekansýný 16 Hz’lik deðiþimlerle arttýran/azaltan PWM uygulamasýný yazarak çalýþtýrýnýz.
#include <16f877A.h>
#fuses HS,NOWDT,NOPROTECT,NODEBUG,NOLVP
#use delay (clock=20M) 
#use fast_io(b) 
#use fast_io(c) 

int x=75; 
int y=155;

void main ( ){
setup_psp(PSP_DISABLED) ; 
setup_spi(SPI_SS_DISABLED) ; 
setup_timer_1(T1_DISABLED) ;
setup_adc_ports(NO_ANALOGS) ; 
setup_adc(ADC_OFF) ; 
setup_CCP2(CCP_OFF);

set_tris_b(0xFF) ;
set_tris_c(0x00) ;

setup_ccp1(CCP_PWM) ;            
setup_timer_2(T2_DIV_BY_16,y,1); 

set_pwm1_duty(75);

while(1){

if (input(pin_b0)) {
while(input(pin_b0));   
x=x+8;
set_pwm1_duty(x); }

if (input(pin_b1)){
while(input(pin_b1));   
x=x-8;
set_pwm1_duty(x);}


if (input(pin_b3)){
while(input(pin_b3));   
y++;                   
setup_timer_2(T2_DIV_BY_16,y,1); 
}

if (input(pin_b2)){
while(input(pin_b2));
y--;    
setup_timer_2(T2_DIV_BY_16,y,1); 
}
}
}
