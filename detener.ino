void detener() {
  
  Serial.println("Deteniendo");
  BT.println("Deteniendo");
  
  uint8_t i;
  
  myMotorLeft->run(FORWARD);
  myMotorRight->run(FORWARD);

  i = 0;
  
  myMotorLeft->setSpeed(i);  
  myMotorRight->setSpeed(i);
  
  delay(5);
}
