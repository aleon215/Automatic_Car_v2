void giro_izquierda() {

  Serial.println("--------- Giro IZQUIERDA");
  BT.println("--------- Giro IZQUIERDA");
  
  uint8_t i;
      
  myMotorLeft->run(BACKWARD);
  myMotorRight->run(FORWARD);
    
  i = 80;
  myMotorLeft->setSpeed(i);  
  
  i = 150;
  myMotorRight->setSpeed(i);
    
  delay(delay_giro);
}
