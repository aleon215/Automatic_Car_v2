

long medir_distancia (int sensor) {
  
  unsigned long distancia;
  unsigned long tiempo;
  
  if (sensor == 1) {
    
    // Getting distance sensor 1 (delantero izquierdo, mirado el coche de frente)
    
    digitalWrite(11, LOW); /* envío del pulso ultrasónico*/
    delayMicroseconds(2);
    digitalWrite(11, HIGH); /* Por cuestión de estabilización del sensor*/
    delayMicroseconds(10);
    tiempo = pulseIn(10, HIGH);
    distancia = tiempo / 58; /*fórmula para calcular la distancia obteniendo un valor entero*/
    Serial.print("Delantero izquierdo: ");
    Serial.println(distancia);
    BT.print("Delantero izquierdo: ");
    BT.println(distancia);
    return distancia;
  }
  
  if (sensor == 2) {
    
    // Getting distance sensor 2 (delantero derecho, mirado el coche de frente)
    
    digitalWrite(13, LOW); /* envío del pulso ultrasónico*/
    delayMicroseconds(2);
    digitalWrite(13, HIGH); /* Por cuestión de estabilización del sensor*/
    delayMicroseconds(10);
    tiempo = pulseIn(12, HIGH);
    distancia = tiempo / 58; /*fórmula para calcular la distancia obteniendo un valor entero*/
    Serial.print("Delantero derecho: ");
    Serial.println(distancia);
    BT.print("Delantero derecho: ");
    BT.println(distancia);
    return distancia;
  }
}
