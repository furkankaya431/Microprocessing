//Butondan yükselen kenar kesme geldiðinde RD0 pinine baðlý ledi yakan, ikinci kesme geldiðinde ise söndüren uygulama
#include <16f877a.h>
#FUSES HS,NOWDT,NODEBUG,NOLVP,NOPROTECT
#use delay(clock=20M)

#define led0 pin_d0

#int_ext
void ext_kesmesi()
{
  output_high(0x01);
  if(input(pin_b0)) {output_toggle(led0);}
}

void main()
{ 
 set_tris_b(0x01);
 set_tris_d(0x00);
 output_d(0x00);
 
 ext_int_edge(L_TO_H);
 enable_interrupts(INT_EXT);
 enable_interrupts(GLOBAL);
 
 while(1);
}
 
