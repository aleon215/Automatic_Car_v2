void giro_izquierda(int delay_giro_in) {

  Serial.print(F("---- Giro IZQUIERDA: "));
  Serial.print(delay_giro_in);
  Serial.println(F(" ms"));
  
  BT.print(F("---- Giro IZQUIERDA: "));
  BT.print(delay_giro_in);
  BT.println(F(" ms"));
  
  uint8_t i;
      
  myMotorLeft->run(BACKWARD);
  myMotorRight->run(FORWARD);
    
  i = 80;
  myMotorLeft->setSpeed(i);  
  
  i = 150;
  myMotorRight->setSpeed(i);
    
  delay(delay_giro_in);
}
