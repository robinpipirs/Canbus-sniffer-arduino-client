#include <defaults.h>
#include <global.h>
#include <SD.h>
#include <SPI.h>

File printFile;
String buffer;
boolean SDfound;
unsigned long time;

void setup()
{
  Serial.begin(115200);

  if (SDfound == 0) {
    if (!SD.begin(53)) {
      Serial.print("The SD card cannot be found");
      while(1);
    }
  }
  SDfound = 1;
  printFile = SD.open("can_data.txt");

  if (!printFile) {
    Serial.print("The text file cannot be opened");
    while(1);
  }


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


