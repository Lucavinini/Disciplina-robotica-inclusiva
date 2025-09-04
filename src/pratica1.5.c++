#include <Servo.h>

// Definição dos pinos conectados ao joystick e aos servos
#define VRX_PIN A0         // Pino do Arduino conectado ao pino VRX (eixo X do joystick)
#define VRY_PIN A1         // Pino do Arduino conectado ao pino VRY (eixo Y do joystick)
#define SERVO_X_PIN 2      // Pino do Arduino conectado ao servo motor 1 (eixo X)
#define SERVO_Y_PIN 3      // Pino do Arduino conectado ao servo motor 2 (eixo Y)

// Criação dos objetos para controlar os servos
Servo xServo;  // Objeto para controlar o servo do eixo X
Servo yServo;  // Objeto para controlar o servo do eixo Y

void setup() {
  Serial.begin(9600);              // Inicia a comunicação serial com o monitor serial
  xServo.attach(SERVO_X_PIN);      // Conecta o servo X ao pino definido
  yServo.attach(SERVO_Y_PIN);      // Conecta o servo Y ao pino definido
}

void loop() {
  // Lê os valores analógicos dos eixos X e Y do joystick
  int xValue = analogRead(VRX_PIN);
  int yValue = analogRead(VRY_PIN);

  // Converte os valores lidos (0 a 1023) para o intervalo de ângulo dos servos (0 a 180 graus)
  int xAngle = map(xValue, 0, 1023, 0, 180);
  int yAngle = map(yValue, 0, 1023, 0, 180);

  // Move os servos para os ângulos calculados
  xServo.write(xAngle);  // Move o servo do eixo X
  yServo.write(yAngle);  // Move o servo do eixo Y

  // Imprime os valores no monitor serial para depuração
  Serial.print("Joystick: ");
  Serial.print(xValue);
  Serial.print(", ");
  Serial.print(yValue);
  Serial.print(" => Servo Motor: ");
  Serial.print(xAngle); 
  Serial.print("°, ");
  Serial.print(yAngle);
  Serial.println("°");
}
