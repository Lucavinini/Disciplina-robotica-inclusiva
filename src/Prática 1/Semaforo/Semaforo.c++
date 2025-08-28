void setup() {
 pinMode(1, OUTPUT);
 pinMode(2, OUTPUT);
 pinMode(3, OUTPUT);
}

void loop() {
 for (int i = 0; i < 3; i++) {
 digitalWrite(3, HIGH);
 delay(10000);
 digitalWrite(3, LOW);
 digitalWrite(2, HIGH);
 delay(2000);
 digitalWrite(2, LOW);
 digitalWrite(1, HIGH);
 delay(10000);
 digitalWrite(1, LOW);
 }
}