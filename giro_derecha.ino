void giro_derecha() {
  
  Serial.println("Giro derecha ---------------------   DDDDDDDDDDDDD");
  BT.println("Giro derecha ---------------------   DDDDDDDDDDDDD");
  
  uint8_t i;
      
  myMotorLeft->run(FORWARD);
  myMotorRight->run(BACKWARD);
        
  i = 80;
  myMotorLeft->setSpeed(i);  

  i = 150;
  myMotorRight->setSpeed(i); 
        
  delay(delay_giro);
}
