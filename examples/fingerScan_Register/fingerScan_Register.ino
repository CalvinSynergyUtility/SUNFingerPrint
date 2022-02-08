#include <SUN_Fingerprint.h>
SUN_Fingerprint finger = SUN_Fingerprint(&Serial2);

uint8_t id;
bool fingerReg = false;
unsigned long  currentFingerReg = 0;
unsigned long intervalFingerReg = 20000;
unsigned long currentFingerScan = 0;
unsigned long intervalFingerScan = 10;

void setup()
{
  Serial.begin(9600);
  finger.begin(57600);
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }
  Serial.println("pilih menu:");
  Serial.println("1.register fingerprint");
}

void loop()                     // run over and over again
{
  if(Serial.available()){
    int inSerial = Serial.read();
    if(inSerial == '1'){
      fingerReg = true;
      currentFingerReg = millis();
    }
  }
  fingerScan();

  while(fingerReg == true){
    fingerRegister();
  }
}
