

void setup() {
 pinMode(5, OUTPUT);
}

void loop() {
 for (int i = 0; i < 3; i++) {
 digitalWrite(5, HIGH);
 delay(200);
 digitalWrite(5, LOW);
 delay(200);
 }

 delay(600);
 for (int i = 0; i < 3; i++) {
 digitalWrite(5, HIGH);
 delay(600);
 digitalWrite(5, LOW);
 delay(200);
 }
 delay(600);
 for (int i = 0; i < 3; i++) 
 {

 digitalWrite(5, HIGH);
 delay(200);
 digitalWrite(5, LOW);
 delay(200);
 }
 delay(1400);
}
