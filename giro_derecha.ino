void giro_derecha(int delay_giro_in) {
  
  Serial.print(F("---- Giro DERECHA: "));
  Serial.print(delay_giro_in);
  Serial.println(F(" ms"));
  
  BT.print(F("---- Giro DERECHA: "));
  BT.print(delay_giro_in);
  BT.println(F(" ms"));
  
  uint8_t i;
      
  myMotorLeft->run(FORWARD);
  myMotorRight->run(BACKWARD);
        
  i = 80;
  myMotorLeft->setSpeed(i);  

  i = 150;
  myMotorRight->setSpeed(i); 
        
  delay(delay_giro_in);
}
