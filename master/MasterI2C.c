#define F_CPU 16000000UL
#include <avr/io.h>
#include "MasterOperationI2C.h"
#include <util/delay.h>
#include <math.h>
int main(void){
	DDRB = 0b00000001;
    uint8_t Address = 0b00010001;
    uint8_t data;
	Master_begin();
    while(1){
        Master_Start();
        Master_Send(Address); 
        data = Master_Receive();
        Master_Stop();
		_delay_ms(1000); 
		PORTB = (data & 0b00000001);
	   }
    }
	


