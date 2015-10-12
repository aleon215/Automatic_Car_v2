void setup() {
  
  // Laser
  // pinMode(LASER, OUTPUT);
  Serial.begin(9600);
  
  BT.begin(9600); //Velocidad del puerto del módulo Bluetooth

  AFMS.begin();  // create with the default frequency 1.6KHz
  //AFMS.begin(1000);  // OR with a different frequency, say 1KHz
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotorLeft->setSpeed(0);
  myMotorLeft->run(FORWARD);
  // turn on motor
  myMotorLeft->run(RELEASE);
  
  // Set the speed to start, from 0 (off) to 255 (max speed)
  myMotorRight->setSpeed(0);
  myMotorRight->run(FORWARD);
  // turn on motor
  myMotorRight->run(RELEASE);
  
  // Sensores de distancia
  
  // Sensor delantero derecho, mirado el coche de frente
  pinMode(13, OUTPUT); // Activación del pin 9 como salida: para el pulso ultrasónico
  pinMode(12, INPUT); // Activación del pin 8 como entrada: tiempo del rebote del ultrasonido
  
  // Sensor delantero izquierdo, mirado el coche de frente
  pinMode(11, OUTPUT); // Activación del pin 7 como salida: para el pulso ultrasónico
  pinMode(10, INPUT); // Activación del pin 6 como entrada: tiempo del rebote del ultrasonido
  
  // Sensor trasero derecho, mirado el coche de frente
  // pinMode(1, OUTPUT); // Activación del pin 5 como salida: para el pulso ultrasónico
  // pinMode(0, INPUT); // Activación del pin 4 como entrada: tiempo del rebote del ultrasonido
  
    // Sensor trasero izquierdo, mirado el coche de frente
  // pinMode(3, OUTPUT); // Activación del pin 7 como salida: para el pulso ultrasónico
  // pinMode(2, INPUT); // Activación del pin 6 como entrada: tiempo del rebote del ultrasonido
  
  // Led de señal de IR
  // pinMode(LED_PIN, OUTPUT);
  
  // Arrancamos el sensor IR
  // irrecv.enableIRIn();
  
  //pinMode(0, INPUT); // Acelerometro axis X
  //pinMode(1, INPUT); // Acelerometro Axis Y
  
  // LLenamos las variables de temporizador
  timer_new = millis();
  timer_old = millis();
}
