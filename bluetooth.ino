void leer_blootooth() { 
  
  if(BT.available())
    {
      char dato=BT.read();
      if (dato=='A') {
        modo = 0;
        Serial.println("BT=A");
      }
      if (dato=='M') {
        modo = 1;
        Serial.println("BT=M");
      }
      if (dato=='1') {
        adelantar();
        Serial.println("BT=1 (Adelantar)");
      }
      if (dato=='2') {
        detener();
        Serial.println("BT=2 (Detener)");
      }
      if (dato=='3') {
        giro_derecha();
        Serial.println("BT=3 (Derecha)");
      }
      if (dato=='4') {
        giro_izquierda();
        Serial.println("BT=4 (Izquierda)");
      }
      if (dato=='5') {
        retroceder();
        Serial.println("BT=5 (Retroceder)");
      }
    }
    
}
