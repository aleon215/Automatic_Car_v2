void leer_blootooth() { 
  
  if(BT.available())
    {
      char dato=BT.read();
      
      if (dato=='5') {
        modo = 0;
        Serial.println("BT=5 -- Modo Automatico");
        //BT.println("BT=5 -- Modo Automatico");
      }
      if (dato=='6') {
        modo = 1;
        Serial.println("BT=6 -- Modo Manual");
        //BT.println("BT=6 -- Modo Manual");
      }
      if (dato=='1') {
        adelantar();
        Serial.println("BT=1 (Adelantar)");
        //BT.println("BT=1 (Adelantar)");
      }
      if (dato=='0') {
        detener();
        Serial.println("BT=0 (Detener)");
        //BT.println("BT=0 (Detener)");
      }
      if (dato=='4') {
        giro_derecha();
        Serial.println("BT=4 (Derecha)");
        //BT.println("BT=4 (Derecha)");
      }
      if (dato=='3') {
        giro_izquierda();
        Serial.println("BT=3 (Izquierda)");
        //BT.println("BT=3 (Izquierda)");
      }
      if (dato=='2') {
        retroceder();
        Serial.println("BT=2 (Retroceder)");
        //BT.println("BT=2 (Retroceder)");
      }
    }
    
}
