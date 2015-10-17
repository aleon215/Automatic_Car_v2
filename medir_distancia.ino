

long medir_distancia (int sensor) {
  
  unsigned long distancia;
  unsigned long tiempo;
  
  if (sensor == 1) {
    
    // Sensor derecho
    digitalWrite(11, HIGH); /* envío del pulso ultrasónico*/
    delayMicroseconds(10);
    digitalWrite(11, LOW); /* Por cuestión de estabilización del sensor*/
    tiempo = pulseIn(10, HIGH, 15000);
    if (tiempo==0) tiempo=15000;
    distancia = tiempo / 58; /*fórmula para calcular la distancia obteniendo un valor entero*/
    return distancia;
  }
  
  if (sensor == 2) {
    
    // Sensor izquierdo
    digitalWrite(A1, HIGH); 
    delayMicroseconds(10);
    digitalWrite(A1, LOW);
    tiempo = pulseIn(A0, HIGH, 15000);
    if (tiempo==0) tiempo=15000;
    distancia = tiempo / 58; /*fórmula para calcular la distancia obteniendo un valor entero*/
    return distancia;
  }
}
