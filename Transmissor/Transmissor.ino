#include <RH_ASK.h>

#define RF_RX_PIN 13
#define RF_TX_PIN 12

RH_ASK RF_driver(5000, RF_RX_PIN, RF_TX_PIN, 0);

void setup()
{
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  if (RF_driver.init())
  {
    Serial.println("RF init started!");
  }
  else
  {
    Serial.println("RF init failed!");
  }

  Serial.println("RF packet: receiving...");
}

unsigned long _cont = 0;
uint8_t RF_messageReceived[RH_ASK_MAX_MESSAGE_LEN];
uint8_t RF_messageReceived_len;

void loop()
{
  RF_messageReceived_len = sizeof(RF_messageReceived);

  if (RF_driver.recv(RF_messageReceived, &RF_messageReceived_len))
  {
    Serial.printf("RF packet receive [%d bytes]: ", RF_messageReceived_len);
    Serial.println((char *)RF_messageReceived);
  }
}
