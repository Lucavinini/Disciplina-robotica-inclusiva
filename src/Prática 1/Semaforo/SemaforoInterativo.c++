const int ledGreenCar = 8;
const int ledYellowCar = 10;
const int ledRedCar = 12;
const int ledGreenPed = 6;
const int ledRedPed = 4;
const int botPed = 2;
unsigned long tempo;

void setup()
{
tempo = millis();
pinMode(ledGreenCar, OUTPUT);
pinMode(ledYellowCar, OUTPUT);
pinMode(ledRedCar, OUTPUT);
pinMode(ledGreenPed, OUTPUT);
pinMode(ledRedPed, OUTPUT);
pinMode(botPed, INPUT_PULLUP);
digitalWrite(ledGreenCar, 1);
digitalWrite(ledRedPed, 1);
}
void loop(){
    int leitura = digitalRead(botPed);
    if((millis() - tempo) > 5000){

if(leitura == 1){

    digitalWrite(ledGreenCar, LOW);
    digitalWrite(ledYellowCar, HIGH);
    delay(2000);
    digitalWrite(ledYellowCar, LOW);
    digitalWrite(ledRedCar, HIGH);
    delay(1000);
    digitalWrite(ledRedPed, LOW);
    digitalWrite(ledGreenPed, HIGH);
    delay(5000);

for(int i = 0 ; i<5 ; i++){
    digitalWrite(ledGreenPed, LOW);
    delay(500);
    digitalWrite(ledGreenPed, HIGH);
    delay(500);
}

digitalWrite(ledGreenPed, LOW);
digitalWrite(ledRedPed, HIGH);
delay(500);
digitalWrite(ledRedCar, LOW);
digitalWrite(ledGreenCar, HIGH);
tempo = millis();
}
}
}

