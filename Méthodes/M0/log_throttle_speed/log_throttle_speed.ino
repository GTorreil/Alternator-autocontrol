/*
  Connexions : 
  
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4 (for MKRZero SD: SDCARD_SS_PIN)

  * Capteurs : 
  ** Throttle signal sur A0
  ** Vitesse  signal sur A1

 */

#include <SPI.h>
#include <SD.h>

const int chipSelect = 4;

void setup() {
  // see if the card is present and can be initialized:
  if (!SD.begin(chipSelect)) {
    // don't do anything more:
    return;
  }
}

void loop() {
  // make a string for assembling the data to log:
  String dataString = String(millis());
  dataString += ",";

  // Read channels
  for (int analogPin = 0; analogPin < 1; analogPin++) {
    int sensor = analogRead(analogPin);
    dataString += String(sensor);
    if (analogPin < 2) {
      dataString += ",";
    }
  }

  File dataFile = SD.open("datalog.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
  }
}
