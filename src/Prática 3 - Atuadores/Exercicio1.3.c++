#include <Servo.h>   // Biblioteca para controle do servo

Servo servo;         // Cria o objeto do tipo Servo

void setup() {
  servo.attach(9);   // Conecta o servo ao pino digital 9
  servo.write(0);    // Posição inicial em 0 graus
}

void loop() {
  // Movimento do servo de 0 até 180 graus
  for (int pos = 0; pos <= 180; pos += 1) { 
    servo.write(pos);     // Move para a posição atual (pos)
    delay(10);            // Espera 10 ms antes do próximo passo
  }

  // Movimento do servo de 180 até 0 graus
  for (int pos = 180; pos >= 0; pos -= 1) { 
    servo.write(pos);     // Move para a posição atual (pos)
    delay(10);            // Espera 10 ms antes do próximo passo
  }
}
