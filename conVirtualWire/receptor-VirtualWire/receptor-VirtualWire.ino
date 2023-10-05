/* Author: @franckT */
#include <VirtualWire.h>

void setup() {
  Serial.begin(9600); // Inicia la comunicación serial para la consola
  vw_set_rx_pin(2);  // Pin del receptor de datos
  vw_setup(2000);    // Velocidad de datos en bps (ajusta según sea necesario)
  vw_rx_start();     // Iniciar recepción de datos
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen)) {
    // Cuando se recibe una palabra RF, muestra la palabra en la consola
    String receivedWord = (char *)buf;
    Serial.print("Palabra RF recibida: ");
    Serial.println(receivedWord);
  }
}
