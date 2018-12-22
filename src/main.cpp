#include <Arduino.h>
#include "SoftwareSerial.h"
#include "SumoBluefruit.h"
#define SOFTWARE_SERIAL_AVAILABLE 0

void getUserInput(char buffer[], uint8_t maxSize);
void error(const __FlashStringHelper*err);

SumoBluefruit ble;

void setup() {
  // initialize LED digital pin as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(115200);
  Serial.println(F("SumoBlue Command Module"));
  Serial.println(F("-------------------------------------"));

  ble.setup();

  if (ble.get_status() == 0) {
    Serial.println(F("Bluetooth OK"));
  } else {
    Serial.println(ble.get_error());
  }

}

void loop() {
  int input = 0;
  // // Check response status
  // ble.waitForOK();

  if (ble.available()) {
    input = ble.read_uart();
    Serial.print(input, 16);

  }
  // ble.println(F("AT+GATTLIST"));

  // ble.waitForOK();
  // Serial.print(F("Done."));
  // while(1);

}

/*
<- +++,ATZ,ATI,ATE,AT+HELP,AT+FACTORYRESET,AT+DFU,AT+DBGMEMRD,AT+DBGNVMRD,
AT+DBGSTACKSIZE,AT+DBGSTACKDUMP,AT+HWMODELED,AT+HWCONNLED,AT+HWRANDOM,AT+HWGETDIETEMP,
AT+HWGPIOMODE,AT+HWGPIO,AT+HWI2CSCAN,AT+HWADC,AT+HWVBAT,AT+HWPWM,AT+HWPWRDN,
AT+BLEPOWERLEVEL,AT+BLEGETADDRTYPE,AT+BLEGETADDR,AT+BLEGETPEERADDR,AT+BLEBEACON,
AT+BLEGETRSSI,AT+BLEURIBEACON,AT+GAPGETCONN,AT+GAPDISCONNECT,AT+GAPDEVNAME,
AT+GAPDELBONDS,AT+GAPINTERVALS,AT+GAPSTARTADV,AT+GAPSTOPADV,AT+GAPAUTOADV,
AT+GAPSETADVDATA,AT+BLEUARTTX,AT+BLEUARTRX,AT+BLEKEYBOARDCODE,AT+BLEKEYBOARDEN,
AT+BLEKEYBOARD,AT+GATTADDSERVICE,AT+GATTADDCHAR,AT+GATTCHAR,AT+GATTLIST,AT+GATTCLEAR
*/
/**************************************************************************/
/*!
    @brief  Checks for user input (via the Serial Monitor)
*/
/**************************************************************************/
void getUserInput(char buffer[], uint8_t maxSize)
{
  memset(buffer, 0, maxSize);
  while( Serial.available() == 0 ) {
    delay(1);
  }

  uint8_t count=0;

  do
  {
    count += Serial.readBytes(buffer+count, maxSize);
    delay(2);
  } while( (count < maxSize) && !(Serial.available() == 0) );
}
