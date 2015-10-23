void detener() {
  
  Serial.println(F("Deteniendo"));
  BT.println(F("Deteniendo"));
  
  myMotorLeft->run(FORWARD);
  myMotorRight->run(FORWARD);

  for(int i=100; i >= 0 ; i--) {  
    myMotorLeft->setSpeed(i);  
    myMotorRight->setSpeed(i);
    delay(5);
  }
  
  // delay(5);
}
