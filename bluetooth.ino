void leer_blootooth() { 
  
  if(BT.available())
    {
      char dato=BT.read();
      
      switch (dato) {
        case '0':
          detener();
          Serial.println("BT=0 (Detener)");
          BT.println("BT=0 (Detener)");
          break;
          
        case '1':
          adelantar();
          Serial.println("BT=1 (Adelantar)");
          BT.println("BT=1 (Adelantar)");
          break;
          
        case '2':
          retroceder();
          Serial.println("BT=2 (Retroceder)");
          BT.println("BT=2 (Retroceder)");
          break;
          
        case '3':
          giro_izquierda(delay_giro_default);
          Serial.println("BT=3 (Izquierda)");
          BT.println("BT=3 (Izquierda)");
          break;
          
        case '4':
          giro_derecha(delay_giro_default);
          Serial.println("BT=4 (Derecha)");
          BT.println("BT=4 (Derecha)");
          break;
          
        case '5':
          modo = 0;
          Serial.println("BT=5 -- Modo Automatico");
          BT.println("BT=5 -- Modo Automatico");
          break;
          
        case '6':
          modo = 1;
          Serial.println("BT=6 -- Modo Manual");
          BT.println("BT=6 -- Modo Manual");
          break;
          
        case '7':
          digitalWrite (5, HIGH);
          Serial.println("BT=7 -- Laser ON");
          BT.println("BT=7 -- Laser ON");
          break;
          
        case '8':
          digitalWrite (5, LOW);
          Serial.println("BT=7 -- Laser OFF");
          BT.println("BT=7 -- Laser OFF");
          break;
      }
    }
}
