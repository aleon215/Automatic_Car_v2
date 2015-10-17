void giro_derecha() {
  
  Serial.println("--------- Giro DERECHA");
  BT.println("--------- Giro DERECHA");
  
  uint8_t i;
      
  myMotorLeft->run(FORWARD);
  myMotorRight->run(BACKWARD);
        
  i = 80;
  myMotorLeft->setSpeed(i);  

  i = 150;
  myMotorRight->setSpeed(i); 
        
  delay(delay_giro);
}
