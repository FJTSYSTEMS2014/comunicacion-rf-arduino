/* Author: @franckT */
// install rc-switch by sui77
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

void setup() {
  mySwitch.enableTransmit(10); // Habilita la transmisión en el pin 10
  Serial.begin(9600); // Inicia la comunicación serial para la consola
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n'); // Lee los datos desde la consola hasta el carácter de nueva línea
    long numData = data.toInt(); // Convierte los datos a un número entero largo

    if (numData != 0) {
      Serial.print("Enviando: ");
      Serial.println(numData);
      mySwitch.send(numData, 24); // Envía los datos (24 bits)
    }
  }
}
