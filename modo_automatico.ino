void modo_automatico() {
  
  // Guardamos los valores de los sensores de distancia
  int dist_delantero_izq = medir_distancia(1);
  delay(5);
  int dist_delantero_der = medir_distancia(2);
  delay(5);
  // int dist_trasero_izq = medir_distancia(3);
  // int dist_trasero_der = medir_distancia(4);
  
  // Comparamos la distancia obtenida por cada sensor para decidir si giramos a la derecha o a la izquierda
  if ((dist_delantero_izq < distancia_minima) | (dist_delantero_der < distancia_minima)) {
    if (dist_delantero_der < dist_delantero_izq) {
      timer_old = millis();
      retroceder();
      giro_derecha();
      detener();
      delay(50);
    }
    else {
      timer_old = millis();
      retroceder();
      giro_izquierda();
      detener();
      delay(50);
    }
  } 
  
  // Si los sensores de distancia no detectan obstaculos, vamos hacia adelante!
  // A menos que el coche lleve 15 segundos seguidos sin girar, entonces podria estar detenido y forzamos el giro
  
  else {
    timer_new = millis();
    if ((timer_new-timer_old)>(tiempo_maximo*1000)) {
      retroceder();
      retroceder();
      giro_izquierda();
      timer_old = millis();
    }
    adelantar();
  }
}
