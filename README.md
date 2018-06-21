#canbus-sniffer-arduino-to-serial


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
