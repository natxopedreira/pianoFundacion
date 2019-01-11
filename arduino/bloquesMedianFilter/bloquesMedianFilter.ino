#include <Wire.h> 
#include "RunningMedian.h"


RunningMedian lecturas[15] = RunningMedian(30);
RunningMedian lecturaLast = RunningMedian(30);
uint8_t direcciones[] = {0x08,0x09,0x0A,0x0B,0x0C,0x0D,0x0E,0x0F,0x10,0x11,0x12,0x13,0x14,0x15,0x16,0x17};

//-----------------------------------------//
void setup() {
  Wire.begin();
  //Wire.setClock(10000);
  Serial.begin(38400);

  /////////////////////////
  // ponemos los ajustes //
  for(uint8_t i = 0; i < 16; i++){
    // ponemos el FOV
    set_fov_16_mod(direcciones[i]);
    // measurement mode
    measurement_mode_long(direcciones[i]);
  }
  

}

//-----------------------------------------//
void loop() {
  // put your main code here, to run repeatedly:
  for(uint8_t i = 0; i < 16; i++){
    if(i == (15)){
        lecturaLast.add(simple_read(direcciones[i]));
        
        Serial.print((int)lecturaLast.getAverage());
        //Serial.print((int)lecturaLast.getMedian());
        Serial.println("");
      }else{
        lecturas[i].add(simple_read(direcciones[i]));
        Serial.print((int)lecturas[i].getAverage());
        //Serial.print((int)lecturas[i].getMedian());
        Serial.print(";");
     }
  }
  //delay(1000);
 
}


//-----------------------------------------//
void set_fov_16(uint8_t address)
{

  Wire.beginTransmission(address);
  Wire.write(0x70);
  Wire.write((byte)5);
  Wire.write((byte)10);
  Wire.write((byte)10);
  Wire.write((byte)5);
  Wire.endTransmission();
}
void set_fov_16_mod(uint8_t address)
{

  Wire.beginTransmission(address);
  Wire.write(0x70);
  Wire.write((byte)5);
  Wire.write((byte)15);
  Wire.write((byte)10);
  Wire.write((byte)10);
  Wire.endTransmission();
}
//-----------------------------------------//
void measurement_mode_long(uint8_t address)
{
  Wire.beginTransmission(address);
  Wire.write(0x6d);
  Wire.write(0x6c);
  Wire.endTransmission();
}

uint16_t simple_read(uint8_t address) {
  Wire.requestFrom(address, 2);
  uint16_t distance = Wire.read() << 8; distance |= Wire.read(); 
  return distance;
}
