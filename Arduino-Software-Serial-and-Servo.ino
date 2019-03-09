#include <VarSpeedServo.h>
#include <SoftwareSerial.h>

VarSpeedServo myservo;    // create servo object to control a servo 
SoftwareSerial mySerial(2, 4); // RX, TX

String incoming;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  mySerial.begin(9600);
} 
 
void loop() {

   if (mySerial.available()) {
    incoming = mySerial.readString();
    mySerial.println(incoming);
  }
  myservo.write(180, 30, true);        // move to 180 degrees, use a speed of 30, wait until move is complete
  myservo.write(0, 30, true);        // move to 0 degrees, use a speed of 30, wait until move is complete
}
