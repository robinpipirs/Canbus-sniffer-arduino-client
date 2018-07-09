#include <defaults.h>
#include <global.h>
#include <SD.h>
#include <SPI.h>

File printFile;
String buffer;
boolean SDfound;
unsigned long time;
// Chip Select pin is tied to pin 9 on the SparkFun CAN-Bus Shield
const int chipSelect = 9;  

void setup()
{
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }

  Serial.print("Initializing SD card...");
  // make sure that the default chip select pin is set to
  // output, even if you don't use it:
  pinMode(chipSelect, OUTPUT);

    // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    Serial.println("Card failed, or not present");
    // don't do anything more:
    return;
  }
  Serial.println("card initialized.");

  printFile = SD.open("can_data.txt");

  if (!printFile) {
    Serial.print("The text file cannot be opened");
    while(1);
  }

  delay(2000); 

  Serial.print("Will start transmitting in 5s");

 delay(5000); 

  while (printFile.available()) {
    Serial.println(readLine()); //Printing for debugging purpose     
    delay(3);    
    //do some action here
  }
  printFile.close();
  
}

String readLine() {
  String received = "";
  char ch;
  while (printFile.available()) {
    ch = printFile.read();
    if (ch == '\n') {
      return String(received);
    } else {
      received += ch;
    }
  }
  return "";
}

void loop()
{ 
}


