#include <Servo.h>

// Pinos do joystick
#define VRX_PIN A0     // Eixo X
#define VRY_PIN A1     // Eixo Y
#define SW_PIN  4      // Botão do joystick (pressionado = LOW)

// Pinos dos servos
#define SERVO_X_PIN 2
#define SERVO_Y_PIN 3

// Objetos Servo
Servo xServo;
Servo yServo;

// Variáveis para ângulos
int xAngle = 90;  // posição inicial central
int yAngle = 90;  // posição inicial central

// Configuração dos limites
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;
const int STEP = 5;   // tamanho do passo
const int DEADZONE = 200; // zona morta em torno do centro (para evitar ruído)

void setup() {
  Serial.begin(9600);

  // Anexa servos
  xServo.attach(SERVO_X_PIN);
  yServo.attach(SERVO_Y_PIN);

  // Posição inicial central
  xServo.write(xAngle);
  yServo.write(yAngle);

  // Configura botão
  pinMode(SW_PIN, INPUT_PULLUP); // joystick botão é normalmente HIGH
}

void loop() {
  // Lê joystick
  int xValue = analogRead(VRX_PIN);
  int yValue = analogRead(VRY_PIN);
  int swValue = digitalRead(SW_PIN);

  // Controle do eixo X (esquerda/direita)
  if (xValue < (512 - DEADZONE)) {       // Esquerda
    xAngle += STEP;
    if (xAngle > MAX_ANGLE) xAngle = MAX_ANGLE;
    xServo.write(xAngle);
    delay(100); // tempo entre passos
  }
  else if (xValue > (512 + DEADZONE)) {  // Direita
    xAngle -= STEP;
    if (xAngle < MIN_ANGLE) xAngle = MIN_ANGLE;
    xServo.write(xAngle);
    delay(100);
  }

  // Controle do eixo Y (cima/baixo)
  if (yValue < (512 - DEADZONE)) {       // Cima
    yAngle += STEP;
    if (yAngle > MAX_ANGLE) yAngle = MAX_ANGLE;
    yServo.write(yAngle);
    delay(100);
  }
  else if (yValue > (512 + DEADZONE)) {  // Baixo
    yAngle -= STEP;
    if (yAngle < MIN_ANGLE) yAngle = MIN_ANGLE;
    yServo.write(yAngle);
    delay(100);
  }

  // Botão pressionado → reseta para centro
  if (swValue == LOW) {
    xAngle = 90;
    yAngle = 90;
    xServo.write(xAngle);
    yServo.write(yAngle);
    delay(300); // debounce
  }

  // Debug
  Serial.print("Joystick X: "); Serial.print(xValue);
  Serial.print(" Y: "); Serial.print(yValue);
  Serial.print(" | ServoX: "); Serial.print(xAngle);
  Serial.print(" ServoY: "); Serial.println(yAngle);
}
