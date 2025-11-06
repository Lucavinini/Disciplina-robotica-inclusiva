#include <Servo.h>

Servo myservo_SobrancelhaES; 
Servo myservo_SobrancelhaDI;
Servo myservo_olhoES;
Servo myservo_olhoDI;
Servo myservo_boca;

int mov  = 90;

void setup(){
  myservo_SobrancelhaES.attach(3);
  myservo_SobrancelhaDI.attach(4);
  myservo_olhoES.attach(5);
  myservo_olhoDI.attach(6);
  myservo_boca.attach(7);
}

void loop(){
  int mov;
  Rosto_Normal();
  delay(1000);
  Rosto_Raiva();
  delay(1000);
  Rosto_triste();
  delay(1000);
  Boca_AbFe();
}

void Rosto_Normal(){
  myservo_SobrancelhaES.write(90);
  myservo_SobrancelhaDI.write(90);
  myservo_olhoES.write(90);
  myservo_olhoDI.write(90);
  myservo_boca.write(90);
}

void Rosto_Raiva(){
  myservo_SobrancelhaES.write(60);
  myservo_SobrancelhaDI.write(110);
  myservo_olhoES.write(110);
  myservo_olhoDI.write(60);
  myservo_boca.write(120);
}
void Rosto_triste(){
  myservo_SobrancelhaES.attach(110);
  myservo_SobrancelhaDI.attach(60);
  myservo_olhoES.attach(60);
  myservo_olhoDI.attach(110);
  myservo_boca.attach(100);
}
void Boca_AbFe(){
  
  for (mov = 90; mov <=110; mov += 1) {
    myservo_boca.write(mov); // Envia o comando para a posição
    delay(15);          // Espera 15 milissegundos para o servo chegar na posição
  }
  for (mov = 110; mov <=90; mov -= 1) {
    myservo_boca.write(mov); // Envia o comando para a posição
    delay(15);          // Espera 15 milissegundos para o servo chegar na posição
  }
}
