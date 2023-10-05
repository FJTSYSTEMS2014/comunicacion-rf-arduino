/* Author: @franckT */
#include <VirtualWire.h>

void setup() {
  vw_set_tx_pin(10); // Pin de transmisión
  vw_setup(2000);    // Velocidad de datos en bps (ajusta según sea necesario)
  Serial.begin(9600); // Inicia la comunicación serial para la consola
}

void loop() {
  // Espera a que el usuario ingrese una palabra por teclado
  Serial.println("Ingresa la palabra a enviar:");
  while (!Serial.available()) {
    // Espera hasta que el usuario ingrese datos
  }

  String word = Serial.readStringUntil('\n'); // Lee la palabra ingresada

  // Envía la palabra RF
  vw_send((uint8_t *)word.c_str(), word.length() + 1); // Enviar la palabra incluyendo el carácter nulo
  vw_wait_tx(); // Esperar a que se complete la transmisión

  Serial.println("Palabra RF enviada:");
  Serial.println(word);

  delay(1000); // Espera un momento antes de volver a enviar (ajusta según sea necesario)
}
