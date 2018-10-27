#include <defaults.h>
#include <global.h>
#include <SPI.h>

//Define LED pins
#define LED1 13

void setup()
{ 
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

 delay(100); 
  
}

void loop()
{ 

//Write LED pins low to turn them off by default
  digitalWrite(LED1, LOW);

  // blink led.. to know its operational
  Serial.println("T: 14139 ID: 223, Data: 0 0 0 0 0 0 32 5F"); //Printing for debugging purpose 
  delay(10);    
  Serial.println("T: 14142 ID: 22, Data: 1 E2 1 E2 0 0 0 F0"); //Printing for debugging purpose     
  delay(10);
  Serial.println("T: 14146 ID: B0, Data: 19 30 19 73 0 5"); //Printing for debugging purpose     
  delay(10);
  Serial.println("T: 14150 ID: 224, Data: 0 0 0 0 0 1 0 0"); //Printing for debugging purpose    
  delay(10);
  Serial.println("T: 14153 ID: 262, Data: 20 1 0 6 90"); //Printing for debugging purpose     
  delay(10);
  Serial.println("T: 14156 ID: B4, Data: 0 0 0 0 1 1A 2 D9"); //Printing for debugging purpose     
  delay(10);
  Serial.println("T: 14160 ID: 4C8, Data: 9 0 8 2 0 0 0 0"); //Printing for debugging purpose     
  delay(10);
  Serial.println("T: 14163 ID: B0, Data: 19 3B 19 71 0 6");
  delay(10);
  Serial.println("T: 14168 ID: 58D, Data: 64 90 0");
  delay(10);
  Serial.println("T: 14170 ID: 20, Data: 0 9 7");
  delay(10);
  Serial.println("T: 14173 ID: B4, Data: 0 0 0 0 1 1A 8 DF");
  delay(10);
  Serial.println("T: 14178 ID: B0, Data: 19 4B 19 77 0 7");
  delay(10);
  Serial.println("T: 14180 ID: 224, Data: 0 0 0 0 0 1 0 0");
  delay(10);
  Serial.println("T: 14185 ID: 20, Data: 0 9 7");
  delay(10);
  Serial.println("T: 14186 ID: B4, Data: 0 0 0 0 1 1A 4 DB");
  delay(10);
  Serial.println("T: 14190 ID: 22, Data: 1 E3 1 E2 0 0 0 F1");
  delay(10);
  Serial.println("T: 14193 ID: 2C1, Data: 0 B D9 B D9 96 37 60");
  delay(10);
  Serial.println("T: 14197 ID: B2, Data: 19 3D 19 82 0 8"); 
  delay(10);   

//Write LED pins high to turn on.
  digitalWrite(LED1, HIGH);
  delay(50);

}


