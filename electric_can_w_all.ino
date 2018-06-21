#include <Canbus.h>  // don't forget to include these
#include <defaults.h>
#include <global.h>
#include <mcp2515.h>
#include <SPI.h>
#include <mcp2515_defs.h>

tCAN speed_message;
tCAN speed_message_a;
tCAN speed_message_b;
tCAN steering_message;
tCAN torq_message;
tCAN rpm_message;
tCAN e_message;
tCAN d_message;
tCAN c_message;


void setup()
{
Serial.begin(115200);
//Initialise MCP2515 CAN controller at the specified speed
if(Canbus.init(CANSPEED_500))
  Serial.println("CAN Init ok");
else
  Serial.println("Can't Init CAN");

delay(1000);


// speed sensor B4 00 00 00 00 01 1D 7E 58
speed_message.id = 0xB4; //formatted in HEX
speed_message.header.rtr = 0;
speed_message.header.length = 8; //formatted in DEC
speed_message.data[0] = 0x00;
speed_message.data[1] = 0x00;
speed_message.data[2] = 0x00;
speed_message.data[3] = 0x00; //formatted in HEX
speed_message.data[4] = 0x00;
speed_message.data[5] = 0x00;
speed_message.data[6] = 0x00;
speed_message.data[7] = 0xBC;

// speed sensor B0 00 00 00 00 01 1D 7E 58
speed_message_a.id = 0x0B0; //formatted in HEX
speed_message_a.header.rtr = 0;
speed_message_a.header.length = 8; //formatted in DEC
speed_message_a.data[0] = 0x00;
speed_message_a.data[1] = 0x00;
speed_message_a.data[2] = 0x00;
speed_message_a.data[3] = 0x00; //formatted in HEX
speed_message_a.data[4] = 0x11;
speed_message_a.data[5] = 0x02;
speed_message_a.data[6] = 0x00;
speed_message_a.data[7] = 0x00;

// speed sensor B2 00 00 00 00 01 1D 7E 58
speed_message_b.id = 0x0B2; //formatted in HEX
speed_message_b.header.rtr = 0;
speed_message_b.header.length = 8; //formatted in DEC
speed_message_b.data[0] = 0x00;
speed_message_b.data[1] = 0x00;
speed_message_b.data[2] = 0x00;
speed_message_b.data[3] = 0x00; //formatted in HEX
speed_message_b.data[4] = 0x11;
speed_message_b.data[5] = 0x02;
speed_message_b.data[6] = 0x00;
speed_message_b.data[7] = 0x00;

// steering sensor 25 00 00 00 00 01 1D 7E 58
steering_message.id = 0x25; //formatted in HEX
steering_message.header.rtr = 0;
steering_message.header.length = 8; //formatted in DEC
steering_message.data[0] = 0x01;
steering_message.data[1] = 0x15;
steering_message.data[2] = 0x00;
steering_message.data[3] = 0x09; //formatted in HEX
steering_message.data[4] = 0x0A;
steering_message.data[5] = 0x0A;
steering_message.data[6] = 0x96;
steering_message.data[7] = 0xF6;

// torq T: 36831 ID: 260, Data: 8 FF CC 0 0 FF F9 35 
torq_message.id = 0x260; //formatted in HEX
torq_message.header.rtr = 0;
torq_message.header.length = 8; //formatted in DEC
torq_message.data[0] = 0x08;
torq_message.data[1] = 0x01;
torq_message.data[2] = 0x4D;
torq_message.data[3] = 0x00; //formatted in HEX
torq_message.data[4] = 0x00;
torq_message.data[5] = 0x0A;
torq_message.data[6] = 0x80;
torq_message.data[7] = 0x4A;

// T: 7406 ID: 20, Data: 0 9 7  
e_message.id = 0x20; //formatted in HEX
e_message.header.rtr = 0;
e_message.header.length = 3; //formatted in DEC
e_message.data[0] = 0x00;
e_message.data[1] = 0x09;
e_message.data[2] = 0x07;
e_message.data[3] = 0x00; //formatted in HEX
e_message.data[4] = 0x00;
e_message.data[5] = 0x00;
e_message.data[6] = 0x00;
e_message.data[7] = 0x00;

// T: 7392 ID: 22, Data: 1 F6 1 F4 0 0 0 16   
d_message.id = 0x22; //formatted in HEX
d_message.header.rtr = 0;
d_message.header.length = 8; //formatted in DEC
d_message.data[0] = 0x01;
d_message.data[1] = 0xF6;
d_message.data[2] = 0x01;
d_message.data[3] = 0xF4; //formatted in HEX
d_message.data[4] = 0x00;
d_message.data[5] = 0x00;
d_message.data[6] = 0x00;
d_message.data[7] = 0x16;

// rpm message 2C4 00 00 00 00 01 1D 7E 58
rpm_message.id = 0x2C4; //formatted in HEX
rpm_message.header.rtr = 0;
rpm_message.header.length = 8; //formatted in DEC
rpm_message.data[0] = 0x07;
rpm_message.data[1] = 0x7D;
rpm_message.data[2] = 0x00;
rpm_message.data[3] = 0x12; //formatted in HEX
rpm_message.data[4] = 0x00;
rpm_message.data[5] = 0x00;
rpm_message.data[6] = 0x92;
rpm_message.data[7] = 0xF6;

// 2C1, Data: 0 19 51 19 51 92 5E 8F 
c_message.id = 0x2C1; //formatted in HEX
c_message.header.rtr = 0;
c_message.header.length = 8; //formatted in DEC
c_message.data[0] = 0x00;
c_message.data[1] = 0x19;
c_message.data[2] = 0x51;
c_message.data[3] = 0x19; //formatted in HEX
c_message.data[4] = 0x51;
c_message.data[5] = 0x92;
c_message.data[6] = 0x5E;
c_message.data[7] = 0x8F;

}
void loop()
{ 
tCAN message;

mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
Serial.println(mcp2515_send_message(&speed_message_b));
delay(1);
Serial.println(mcp2515_get_message(&message));
while(!mcp2515_check_free_buffer()){
  Serial.println("wait");
delay(1);
  }

mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
Serial.println(mcp2515_send_message(&speed_message));
delay(1);
Serial.println(mcp2515_get_message(&message));
while(!mcp2515_check_free_buffer()){
delay(1);
  }

mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
Serial.println(mcp2515_send_message(&speed_message_a));
delay(1);
Serial.println(mcp2515_get_message(&message));

  
mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
Serial.println(mcp2515_send_message(&speed_message_b));
delay(1);
Serial.println(mcp2515_get_message(&message));

mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
mcp2515_send_message(&steering_message);
Serial.println("msg 4 sent");
delay(1);
Serial.println(mcp2515_get_message(&message));


mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
mcp2515_send_message(&torq_message);
Serial.println("msg 5 sent");
delay(1);
Serial.println(mcp2515_get_message(&message));


mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
mcp2515_send_message(&rpm_message);
Serial.println("msg 6 sent");
delay(1);
Serial.println(mcp2515_get_message(&message));

mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
mcp2515_send_message(&e_message);
Serial.println("msg 7 sent");
delay(1);
Serial.println(mcp2515_get_message(&message));

mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
mcp2515_send_message(&d_message);
Serial.println("msg 8 sent");
delay(1);
Serial.println(mcp2515_get_message(&message));

mcp2515_bit_modify(CANCTRL, (1<<REQOP2)|(1<<REQOP1)|(1<<REQOP0), 0);
mcp2515_send_message(&c_message);
Serial.println("msg 9 sent");
delay(1);
Serial.println(mcp2515_get_message(&message));
}
