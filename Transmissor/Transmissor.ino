#include <RH_ASK.h>

#define RF_RX_PIN 13
#define RF_TX_PIN 12

RH_ASK RF_driver(5000, RF_RX_PIN, RF_TX_PIN, 0);

void setup()
{
  Serial.begin(115200);
  delay(5000);
  Serial.setDebugOutput(true);
  if (RF_driver.init())
  {
    Serial.println("RF init started!");
  }
  else
  {
    Serial.println("RF init failed!");
  }
}

void loop(){
     
    unsigned long _cont = 0;
    char msg[27];
    
    sprintf(msg, "value: %ld", _cont++);
    Serial.println("RF packet: sending...");
    Serial.println(msg);
    RF_driver.send((uint8_t *)msg, strlen(msg));
    RF_driver.waitPacketSent();
    delay(5000);
}
