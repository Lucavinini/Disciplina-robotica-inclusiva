/* 

Implemente um código que faça com que o LED fique:
- 3 segundos aceso e 3 segundos apagado
- 200 milissegundos aceso e 500 milissegundos apagado

*/

void setup() {
 pinMode(5, OUTPUT);
}

void loop() {

 digitalWrite(5, HIGH);
 delay(3000);
 digitalWrite(5, LOW);
 delay(3000);

}