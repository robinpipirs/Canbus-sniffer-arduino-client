# canbus-sniffer-arduino-to-serial

This Arduino software translates incoming canbus to serial string. Which the Java client can read.
You install this as any other Arduino examples. canbus-sniffer-arduino-to-serial.ino is the file to run.
Once the Arduino is flashed you can run it with Usb or serial cable with the Java client software.


The Arduino software parses the canbus message and forwards it on serial:
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


### Added can_simulator_text_read.ino:
The `can_simulator_text_read.ino` is used to simulate a car connected for software debugging,
Right now the java client is to slow and misses some messages. 
This examples sends a message like bellow: 
>T: 14142 ID: 22, Data: 1 E2 1 E2 0 0 0 F0


They are sent with 3ms delay, This is to simulate a fast canbus network.
Task is to improve java client with clever thread distrubution to speed things up.
Reason for this is. When a crowded network is used the software isnt fast enough filtering while receiving. Which means we loose messages.
