void modo_automatico() {

  // Guardamos los valores de los sensores de distancia
  long dist_delantero_der = medir_distancia(1);
  delay(60);
  long dist_delantero_izq = medir_distancia(2);
  delay(60);

  Serial.print(F("D: "));
  Serial.print(dist_delantero_der);
  BT.print(F("D: "));
  BT.print(dist_delantero_der);

  Serial.print(F("   I: "));
  Serial.println(dist_delantero_izq);
  BT.print(F("   I: "));
  BT.println(dist_delantero_izq);

  // Comparamos la distancia obtenida por cada sensor para decidir si giramos a la derecha o a la izquierda
  if ((dist_delantero_izq < distancia_minima) || (dist_delantero_der < distancia_minima)) {
    timer_old = millis();
    retroceder();
    
    float calc = (float)min(dist_delantero_izq,dist_delantero_der) / (float)max(dist_delantero_izq,dist_delantero_der);
    int delay_giro = mapfloat(calc,0,1,350,500);
    
    Serial.print(F("--- Calc: "));
    Serial.print(calc);
    Serial.print(F(" - Delay giro: "));
    Serial.println(delay_giro);
    
    BT.print(F("--- Calc: "));
    BT.print(calc);
    BT.print(F(" - Delay giro: "));
    BT.println(delay_giro);

    if (dist_delantero_der < dist_delantero_izq) giro_izquierda(delay_giro);
    else giro_derecha(delay_giro);

    detener();
    
  }

  // Si los sensores de distancia no detectan obstaculos, vamos hacia adelante!
  // A menos que el coche lleve 15 segundos seguidos sin girar, entonces podria estar detenido y forzamos el giro
  else {
    timer_new = millis();
    if ((timer_new - timer_old) > (tiempo_maximo * 1000)) {
      Serial.println(F("--------- Giro por TIEMPO"));
      BT.println(F("--------- Giro por TIEMPO"));
      retroceder();
      retroceder();
      giro_izquierda(delay_giro_default);
      timer_old = millis();
    }
    adelantar();
  }
}
