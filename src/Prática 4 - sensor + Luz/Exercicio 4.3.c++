#include <Servo.h> 
const int TRIG_PIN = 9; // Pino TRIG do sensor ultrassônico const 
int ECHO_PIN = 8; // Pino ECHO do sensor ultrassônico const 
int ledPinverde = 4; // Define o pino 4 como o LED const 
int ledPinamarelo = 2; // Define o pino 2 como o LED const 
int ledPinvermelho = 3; // Define o pino 3 como o LED 
int buzzerPin = 5; //Define o pino 5 como saido do buzzer
Servo servo; // Objeto para controle do servo 

void setup() { 
  Serial.begin(9600); // Inicializa a comunicação serial 
  pinMode(TRIG_PIN, OUTPUT); // Define TRIG como saída 
  pinMode(ECHO_PIN, INPUT); // Define ECHO como entrada 
  pinMode(ledPinverde, OUTPUT); // Configura o pino do LED como saída 
  pinMode(ledPinamarelo, OUTPUT); // Configura o pino do LED como saída 
  pinMode(ledPinvermelho, OUTPUT); // Configura o pino do LED como saída 
  servo.attach(6);//Declara a porta de saida do servo motor
} 

void loop(){ 
  digitalWrite(TRIG_PIN, HIGH); 
  delayMicroseconds(10); // Gera pulso de 10 microsegundos 
  digitalWrite(TRIG_PIN, LOW); 
  
  float duration_us = pulseIn(ECHO_PIN, HIGH); // Lê a duração do pulso 
  float distance_cm = 0.017 * duration_us; // Calcula a distância 
  
  if(distance_cm > 100) { 
    digitalWrite(ledPinverde, HIGH); // Liga o LED 
    digitalWrite(ledPinamarelo, LOW); // Desliga o LED 
    digitalWrite(ledPinvermelho, LOW); // Desliga o LED 
    noTone(buzzerPin); //Desativa o buzzer
    servo.write(0);
    
  }else if(distance_cm <= 100 && distance_cm >= 50) { 
    digitalWrite(ledPinverde, LOW); // Desliga o LED 
    digitalWrite(ledPinamarelo, HIGH); // Liga o LED 
    digitalWrite(ledPinvermelho, LOW); // Desliga o LED 
    noTone(buzzerPin);//Desativa o buzzer
    servo.write(90);
  }else{ 
    digitalWrite(ledPinverde, LOW); // Desliga o LED 
    digitalWrite(ledPinamarelo, LOW); // Desliga o LED 
    digitalWrite(ledPinvermelho, HIGH); // Liga o LED 
    tone(buzzerPin, 1000); //Ativa o buzzer
    servo.write(180);
   }


  Serial.print("Distance: "); Serial.print(distance_cm); Serial.println(" cm"); 

  delay(500); // Aguarda meio segundo antes de nova leitura 
} 

 