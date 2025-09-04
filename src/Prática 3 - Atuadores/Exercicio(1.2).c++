#include <Servo.h>
Servo myservo;
int angulo;

void setup(){
Serial.begin(9600);
myservo.attach(9);
myservo.write(0);
}

void loop(){
if (Serial.available( )){
 angulo = Serial.parseInt();
}
myservo.write(angulo);
}