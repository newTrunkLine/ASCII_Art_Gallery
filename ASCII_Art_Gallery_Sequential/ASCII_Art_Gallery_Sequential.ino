#include <SPI.h>
#include <SD.h>

const int chipSelectPin = 4;
const int numPictures = 12;
int counter = 1;

void setup() {
  // Baud rate is directly proportional to time taken to print image, so use a faster one
  Serial.begin(115200);
  while(!Serial){
    ; // Wait for serial port to connect
  }

  Serial.print("Initializing SD card... ");
  if(!SD.begin(chipSelectPin)){
    Serial.println("Card failed, or not present");
    // Don't do anything more
    while(1);
  }
  Serial.println("SD card successfully initialized");
}

void loop() {
  String fileName = String(counter);
  fileName += ".txt";
  Serial.println();
  Serial.print("Now displaying: ");
  Serial.println(fileName);
  
  File dataFile = SD.open(fileName);

  if(dataFile){
    Serial.println();
    while(dataFile.available()){
      Serial.write(dataFile.read());
    }
    Serial.println();
    dataFile.close();
  }
  else{
    Serial.print("Error opening data file ");
    Serial.println(fileName);
  }

  if(counter < numPictures){
    counter++;
  }
  else{
    counter = 1;
  }
  delay(5000);
}
