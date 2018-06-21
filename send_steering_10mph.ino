#include <Canbus.h>  // don't forget to include these
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <mcp2515_defs.h>

void setup()
{
Serial.begin(115200);
//Initialise MCP2515 CAN controller at the specified speed
if(Canbus.init(CANSPEED_500))
  Serial.println("CAN Init ok");
else
  Serial.println("Can't Init CAN");

delay(1000);
}

void loop()
{ 
  tCAN message;

  message.id = 0x00B4; //formatted in HEX
  message.header.rtr = 0;
  message.header.length = 8; //formatted in DEC
  message.data[0] = 0x00;
  message.data[1] = 0x00;
  message.data[2] = 0x00;
  message.data[3] = 0x00; //formatted in HEX
  message.data[4] = 0x00;
  message.data[5] = 0x06;
  message.data[6] = 0x66;
  message.data[7] = 0x28;

  mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
  mcp2515_send_message(&message);

  delay(30);
               
}
