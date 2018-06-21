# canbus-sniffer-arduino-to-serial

This arduino program translates incoming canbus to serial string. Which the Java client can read.
You install this as any other Arduino examples. canbus-sniffer-arduino-to-serial.ino is the file to run.
Once the Arduino is flashed you can run it with Usb or serial cable with Java software.

```c++
   Serial.print("T: ");
   time = millis();
   Serial.print(time);
   Serial.print(" ID: ");
   Serial.print(message.id,HEX);
   Serial.print(", ");
   Serial.print("Data: ");
   for(int i=0;i<message.header.length;i++)
    {
      Serial.print(message.data[i],HEX);
      Serial.print(" ");
    }
   Serial.println("");
```


The structure needed of the serial message in order for java client parser to work is the following:
>T: 14142 ID: 22, Data: 1 E2 1 E2 0 0 0 F0

The same is required for the filter.asc file.
