// Program �al��t�r�ld���nda %50 lik doluluk oran�, 2000 Hz�lik frekans ile �al��maya ba�layan ve 2 adet butonla doluluk oran� %5�lik de�i�imlerle artt�r�labilen ve azalt�labilen,
// di�er 2 adet butonla PWM frekans�n� 16 Hz�lik de�i�imlerle artt�ran/azaltan PWM uygulamas�n� yazarak �al��t�r�n�z.
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
