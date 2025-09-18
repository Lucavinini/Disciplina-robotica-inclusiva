#include <Servo.h> 

const int TRIG_PIN = 9; // Pino TRIG do sensor ultrassônico  

const int ECHO_PIN = 8; // Pino ECHO do sensor ultrassônico  

const int SERVO_PIN = 10; // Pino do servo motor  

const int DISTANCE_THRESHOLD = 50; // Limite de distância (em cm) 

 

Servo servo; // Objeto para controle do servo 

void setup() { 

 Serial.begin(9600); // Inicializa a comunicação serial  

     pinMode(TRIG_PIN, OUTPUT); // Define TRIG como saída  

     pinMode(ECHO_PIN, INPUT); // Define ECHO como entrada 

     servo.attach(SERVO_PIN); // Conecta o servo ao  

     pino 10 servo.write(0); // Inicializa o servo em 0°  

} 

void loop() {  

     digitalWrite(TRIG_PIN, HIGH);  

     delayMicroseconds(10); // Gera pulso de 10 microsegundos  

     digitalWrite(TRIG_PIN, LOW); 

     float duration_us = pulseIn(ECHO_PIN, HIGH); // Lê a duração do pulso  

     float distance_cm = 0.017 * duration_us; // Calcula a distância 

     if (distance_cm < DISTANCE_THRESHOLD) {  

            servo.write(90); // Ajusta o servo para 90° quando um obstáculo é detectado } 

      else {  

            servo.write(0); // Mantém o servo em 0° quando não há obstáculo  

} 

            Serial.print("Distance: ");  

            Serial.print(distance_cm);  

            Serial.println(" cm"); 

            delay(500); // Aguarda meio segundo antes de nova leitura  

} 

 