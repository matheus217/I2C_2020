#include <avr/io.h>

void Master_begin(){
  TWSR = 0x03; 
  TWBR = 0xFF; //frequencia do clock
}

void Master_Send(uint8_t data){
    TWDR = data;
    TWCR = (1<<TWINT) | (1<<TWEN);
    while(!(TWCR & 1<<TWINT));
}

void Master_Start(){
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
    while(!(TWCR & 1<<TWINT));
}

void Master_Stop(){
    TWCR = (1<<TWINT) | (1<<TWSTO) | (1<<TWEN);
}

uint8_t Master_Receive(){
    TWCR = (1<< TWINT) | (1<<TWEN); // lê apenas um byte
    while(!(TWCR & 1 <<TWINT));
    return TWDR;
}
