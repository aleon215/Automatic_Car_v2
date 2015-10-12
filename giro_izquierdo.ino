void giro_izquierda() {

  Serial.println("Giro izquierda ---------------------   IIIIIIIIIIII");
  BT.println("Giro Izquierda ---------------------   IIIIIIIIIIII");
  
  uint8_t i;
      
  myMotorLeft->run(BACKWARD);
  myMotorRight->run(FORWARD);
    
  i = 80;
  myMotorLeft->setSpeed(i);  
  
  i = 150;
  myMotorRight->setSpeed(i);
    
  delay(delay_giro);
}
