/* 
Rishita Sarin & Merwan Yeditha

heehoo
*/

#include <Servo.h>

Servo pan; //Servo controlling panning
Servo tilt; // Servo controlling tilting

int pos_pan = 0;    // variable to store the servo position
int pos_tilt = 0;
int sensorPin = A0;

void setup() {
  Serial.begin(9600);
  pan.attach(9);
  tilt.attach(10);
  pan.write(pos_pan);
  tilt.write(pos_tilt);
  delay(1000);
  // attaches the servo on pin 9 to the servo object
}

void loop() {
  // Pan left-to-right
  while(pos_tilt < 40) {
      for (pos_pan = 0; pos_pan <= 90; pos_pan += 1) {
        pan.write(pos_pan);
        delay(50);
        Serial.print(pos_pan);
        Serial.print(" ");
        Serial.print(pos_tilt);
        Serial.print(" ");
        Serial.println(analogRead(sensorPin));
      }
      pos_tilt += 2;
      tilt.write(pos_tilt);
      delay(50);
      for (pos_pan = 90; pos_pan >= 0; pos_pan -= 1) {
        pan.write(pos_pan);             

        delay(50);
        Serial.print(pos_pan);
        Serial.print(" ");
        Serial.print(pos_tilt);
        Serial.print(" ");
        Serial.println(analogRead(sensorPin));
      }
      pos_tilt += 2;
      tilt.write(pos_tilt);
      delay(50);
  }
  Serial.println("finished");
}
