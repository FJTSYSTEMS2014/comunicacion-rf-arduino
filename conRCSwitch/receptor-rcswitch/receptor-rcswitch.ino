/* Autor:@franckT */
// install rc-switch by sui77
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

int ledPin = 13; // El LED incorporado del Arduino Uno se encuentra en el pin 13

void setup() {
  pinMode(ledPin, OUTPUT); // Configura el pin del LED como salida
  mySwitch.enableReceive(0); // Habilita la recepción en el pin 0 (D2)
  Serial.begin(9600); // Inicia la comunicación serial para la consola
}

void loop() {
  if (mySwitch.available()) {
    unsigned long value = mySwitch.getReceivedValue();
    
    if (value != 0) {
      Serial.print("Señal RF recibida: ");
      Serial.println(value);
      
      digitalWrite(ledPin, HIGH); // Enciende el LED
      delay(1000); // Espera un segundo
      digitalWrite(ledPin, LOW); // Apaga el LED
      
      mySwitch.resetAvailable();
    }
  }
}
