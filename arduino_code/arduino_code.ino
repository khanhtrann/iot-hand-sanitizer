#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"
#include <Servo.h>
SoftwareSerial mySoftwareSerial(12, 11);
DFRobotDFPlayerMini myDFPlayer;
Servo servo;
unsigned int ADCValue;
int servoPIN = 4;
void setup() {
  Serial.begin (9600);
  mySoftwareSerial.begin(9600);
  if (!myDFPlayer.begin(mySoftwareSerial, true, false)) {
    while (true) {
      delay(0);
    }
  }
  myDFPlayer.volume(30);
  servo.attach(servoPIN);
  servo.write(0);
}
void loop() {
  ADCValue = analogRead(A0);
  Serial.print("Khoang cach: ");
  Serial.print(ADCValue, DEC);
  Serial.println("mm");
  if (ADCValue < 100) {
    Serial.println("The distance is less than 100mm");
    servo.write(180);
    delay(2000);
    servo.write(0);
    thankyou();
  }
  if (ADCValue > 600) {
    Serial.println("The distance is more than 600mm");
    remind();
  }
  delay(4000);
}

void remind() {
  myDFPlayer.play(1);
  delay(4000);
}

void thankyou() {
  myDFPlayer.play(2);
  delay(4000);
}
