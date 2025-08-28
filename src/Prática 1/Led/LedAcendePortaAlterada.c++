/*A partir do mesmo código fonte faça uma nova montagem 
deste tutorial e faça as modificações necessárias no código 
fonte para que o LED seja colocado no Pino 5, e fique 2 
segundos aceso e 1 segundo apagado.
*/


void setup() {
 pinMode(5, OUTPUT);
}
void loop() {
 digitalWrite(5, HIGH);
 delay(2000);
 digitalWrite(5, LOW);
 delay(1000);
}