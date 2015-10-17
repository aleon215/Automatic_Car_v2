void modo_automatico() {

  // Guardamos los valores de los sensores de distancia
  long dist_delantero_der = medir_distancia(1);
  delay(100);
  long dist_delantero_izq = medir_distancia(2);
  delay(100);

  Serial.print("D: ");
  Serial.print(dist_delantero_der);
  BT.print("D: ");
  BT.print(dist_delantero_der);

  Serial.print("   I: ");
  Serial.println(dist_delantero_izq);
  BT.print("   I: ");
  BT.println(dist_delantero_izq);

  // Comparamos la distancia obtenida por cada sensor para decidir si giramos a la derecha o a la izquierda
  if ((dist_delantero_izq < distancia_minima) || (dist_delantero_der < distancia_minima)) {
    timer_old = millis();
    retroceder();

    if (dist_delantero_der < dist_delantero_izq) giro_izquierda();
    else giro_derecha();

    detener();
    
  }

  // Si los sensores de distancia no detectan obstaculos, vamos hacia adelante!
  // A menos que el coche lleve 15 segundos seguidos sin girar, entonces podria estar detenido y forzamos el giro
  else {
    timer_new = millis();
    if ((timer_new - timer_old) > (tiempo_maximo * 1000)) {
      Serial.println("--------- Giro por TIEMPO");
      BT.println("--------- Giro por TIEMPO");
      retroceder();
      retroceder();
      giro_izquierda();
      timer_old = millis();
    }
    adelantar();
  }
}
