//#include <Arduino.h>
//#include "OneWire.h"
#include "DallasTemperature.h"
//G -> GND, R -> VCC,Y -> 2
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
void setup()
{
  // start serial port
  Serial.begin(9600);
  Serial.println("Dallas Temperature IC Control Library Demo");
  // Start up the library
  sensors.begin();
}
void loop()
{ 
  // call sensors.requestTemperatures() to issue a global temperature 
  // request to all devices on the bus
  Serial.print("开始获取温度...");
  sensors.requestTemperatures(); // Send the command to get temperatures
  Serial.println("获取完成");
  
  Serial.print("设备1(索引 0),温度是: ");
  Serial.println(sensors.getTempCByIndex(0));
  delay(1000);
}
