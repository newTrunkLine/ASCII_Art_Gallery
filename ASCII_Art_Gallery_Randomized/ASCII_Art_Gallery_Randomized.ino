#include <SPI.h>
#include <SD.h>

const int chipSelectPin = 4;
const int numPictures = 12;
int lastNumber = 0;
int secondLastNumber = 0;

int getRandNumber(){
  // Bounds of generated random number are [1, numPictures]
  return random(1, (numPictures + 1));
}

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

  // Keep A0 disconnected/floating
  // Random noise at A0 will generate different seed values each time
  randomSeed(analogRead(A0));
}

void loop() {
  int randNumber = getRandNumber();

  // Get a random number that isn't the same as the last two random numbers
  // Because otherwise you might see the same few images repeatedly
  while((randNumber == lastNumber) || (randNumber == secondLastNumber)){
    randNumber = getRandNumber();
  }
  
  String fileName = String(randNumber);
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

  secondLastNumber = lastNumber;
  lastNumber = randNumber;
  delay(5000);
}
