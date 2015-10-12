void loop() {

  // Leer bluetooth
  leer_blootooth();
  
  //Activar laser
  // digitalWrite(LASER, HIGH);
  
  // Leer infrarojos
  /*
  
  if (irrecv.decode(&IR_resultados)) {
    //digitalWrite(LED_PIN, HIGH);
    //Serial.println(results.value, DEC);
    irrecv.resume(); // Recibir el siguiente valor
    delay(200);
    
    switch(IR_resultados.value) {
      
      // Boton "POWER mando" SAMSUNG --> modo automatico (default) = 0
      // case 3392264773:
      
      // Boton "MENU" manda APPLE --> modo automatico (default) = 0
      case 2011283554:
        modo=0;
      break;
      
      // Boton "TV POWER" mando SAMSUNG --> modo manual = 1
      // case 3772793023:
      
      // Boton "Play" mando APPLE --> modo manual = 1
      case 2011275362:
        modo=1;
        detener();
      break;
      
      // Boton "Vol+" --> Aumentar velocidad
      //case 3476004267:
      
      // Boton "Vol+" --> Aumentar velocidad
      case 2011254882:
        adelantar();
      break;
      
      // Boton "Vol-" --> Retroceder
      // case 2998643817:
      
      // Boton "Vol-" --> Retroceder
      case 2011246690:
        retroceder();
      break;
      
      // Boton "Level <" --> Girar izquierda
      // case 4218783810:
      
      // Boton "<<" --> Girar izquierda
      case 2011271266:
        giro_izquierda();
      break;
      
      // Boton "Level >" --> Girar derecha
      // case 1863712582:
      
      // Boton ">>" --> Girar derecha
      case 2011258978:
        giro_derecha();
      break;
      
      // Boton "MUTE" --> Detener
      case 305976139:
        detener();
      break;
    }
  }
  

  
  digitalWrite(LED_PIN, LOW);
  
  */
  
  // Reading accelaration
  //accelX = analogRead(0);
  //accelY = analogRead(1);
  //Serial.print("X:  ");
  //Serial.println(accelX);
  //Serial.print("Y:  ");
  //Serial.println(accelY);
  //delay(1000);
  
  if (modo==0) {modo_automatico();}
  
}
