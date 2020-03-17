#include <avr/io.h>

void Slave_Begin(uint8_t SlaveAddress){
  TWCR = 0x04;
  TWAR = SlaveAddress;
  TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
}

void Slave_Listen(){
    while(!(TWCR & (1 <<TWINT)));
}

void Slave_Send(uint8_t data8){
    TWDR = data8;
    TWCR = (1<<TWINT) | (1<<TWEN);
    while(!(TWCR & (1<<TWINT)));
}

uint8_t Slave_Receive(){
      TWCR = (1<< TWINT) | (1<<TWEN);  //LER APENAS 1 BYTE
      while(!(TWCR & (1 <<TWINT)));
      return TWDR;
}