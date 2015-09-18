#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_PWMServoDriver.h"
#include <IRremote.h>

//int accelX;
//int accelY;
int modo = 0; // 0=Auto, 1=Manual

// Laser
// int LASER = 4;

// Configurar variables para sensor IR
int LED_PIN = 4;
int IR_PIN = 5;
IRrecv irrecv(IR_PIN);
decode_results IR_resultados;

// Crear el objeto del driver de motores
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Instanciar los motores
// Adafruit_DCMotor *myMotorLeft = AFMS.getMotor(1);
// Adafruit_DCMotor *myMotorLeft = AFMS.getMotor(2);
Adafruit_DCMotor *myMotorRight = AFMS.getMotor(3);
Adafruit_DCMotor *myMotorLeft = AFMS.getMotor(4);

// Distancia minima detectada por los sensores de distancia para girar, medida en centimetros
int distancia_minima = 10;

// Temporizador
unsigned long timer_new;
unsigned long timer_old;

// Tiempo maximo en segundos para forzar giro si no ha girado solo
int tiempo_maximo = 10;

void setup() {
  
  // Laser
  // pinMode(LASER, OUTPUT);
  Serial.begin(9600);

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
  pinMode(LED_PIN, OUTPUT);
  
  // Arrancamos el sensor IR
  irrecv.enableIRIn();
  
  //pinMode(0, INPUT); // Acelerometro axis X
  //pinMode(1, INPUT); // Acelerometro Axis Y
  
  // LLenamos las variables de temporizador
  timer_new = millis();
  timer_old = millis();
}

void loop() {

  //Activar laser
  // digitalWrite(LASER, HIGH);
  
  // Leer infrarojos
  
  if (irrecv.decode(&IR_resultados)) {
    digitalWrite(LED_PIN, HIGH);
    //Serial.println(results.value, DEC);
    irrecv.resume(); // Recibir el siguiente valor
    delay(200);
    
    switch(IR_resultados.value) {
      
      // Boton "POWER mando" SAMSUNG --> modo automatico (default) = 0
      case 3392264773:
        modo=0;
      break;
      
      // Boton "TV POWER" mando SAMSUNG --> modo manual = 1
      case 3772793023:
        modo=1;
        detener();
      break;
      
      // Boton "Vol+" --> Aumentar velocidad
      case 3476004267:
        adelantar();
      break;
      
      // Boton "Vol-" --> Retroceder
      case 2998643817:
        retroceder();
      break;
      
      // Boton "Level <" --> Girar izquierda
      case 4218783810:
        giro_izquierda();
      break;
      
      // Boton "Level >" --> Girar derecha
      case 1863712582:
        giro_derecha();
      break;
      
      // Boton "MUTE" --> Detener
      case 305976139:
        detener();
      break;
    }
  }
  

  
  digitalWrite(LED_PIN, LOW);
  
  // Reading accelaration
  //accelX = analogRead(0);
  //accelY = analogRead(1);
  //Serial.print("X:  ");
  //Serial.println(accelX);
  //Serial.print("Y:  ");
  //Serial.println(accelY);
  //delay(1000);
  
  if (modo==0) {modo_automatico();}
  
}

long medir_distancia (int sensor) {
  long distancia;
  long tiempo;
  if (sensor==1) {
    // Getting distance sensor 1 (delantero izquierdo, mirado el coche de frente)
    digitalWrite(11,LOW); /* Por cuestión de estabilización del sensor*/ 
    delayMicroseconds(5);
    digitalWrite(11, HIGH); /* envío del pulso ultrasónico*/
    delayMicroseconds(10);
    tiempo=pulseIn(10, HIGH);
    distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
    Serial.print('Delantero izquierdo: ');
    Serial.println(distancia);
    return distancia;
  }
  if (sensor==2) {
     // Getting distance sensor 2 (delantero derecho, mirado el coche de frente)
    digitalWrite(13,LOW); /* Por cuestión de estabilización del sensor*/
    delayMicroseconds(5);
    digitalWrite(13, HIGH); /* envío del pulso ultrasónico*/
    delayMicroseconds(10);
    tiempo=pulseIn(12, HIGH);
    distancia= int(0.017*tiempo); /*fórmula para calcular la distancia obteniendo un valor entero*/
    Serial.print('Delantero derecho: ');
    Serial.println(distancia);
    return distancia;
  }
}

void retroceder() {
    
    Serial.println('Retrocediendo');
    uint8_t i;
    
    myMotorLeft->run(BACKWARD);
    myMotorRight->run(BACKWARD);
    
    i = 80;
    
    myMotorLeft->setSpeed(i);  
    myMotorRight->setSpeed(i); 
    
    delay(400); 
}

void giro_derecha() {
  
  Serial.println("Giro derecha");
  //Serial.println(giro);
  
  uint8_t i;
      
  myMotorLeft->run(FORWARD);
  myMotorRight->run(BACKWARD);
        
  i = 80;
  myMotorLeft->setSpeed(i);  

  i = 140;
  myMotorRight->setSpeed(i); 
        
  delay(200);
}

void giro_izquierda() {

  Serial.println("Giro izquierda");
  //Serial.println(giro);
  
  uint8_t i;
      
  myMotorLeft->run(BACKWARD);
  myMotorRight->run(FORWARD);
    
  i = 80;
  myMotorLeft->setSpeed(i);  
  
  i = 140;
  myMotorRight->setSpeed(i);
    
  delay(200);
}

void adelantar() {
  
  Serial.println('Adelantando');
  
  uint8_t i;
  
  myMotorLeft->run(FORWARD);
  myMotorRight->run(FORWARD);

  i = 150;
  
  myMotorLeft->setSpeed(i);  
  myMotorRight->setSpeed(i);
  
  delay(5);
}

void detener() {
  
  Serial.println('Deteniendo');
  
  uint8_t i;
  
  myMotorLeft->run(FORWARD);
  myMotorRight->run(FORWARD);

  i = 0;
  
  myMotorLeft->setSpeed(i);  
  myMotorRight->setSpeed(i);
  
  delay(5);
}

void modo_automatico() {
  
  // Guardamos los valores de los sensores de distancia
  int dist_delantero_izq = medir_distancia(1);
  int dist_delantero_der = medir_distancia(2);
  // int dist_trasero_izq = medir_distancia(3);
  // int dist_trasero_der = medir_distancia(4);
  
  // Comparamos la distancia obtenida por cada sensor para decidir si giramos a la derecha o a la izquierda
  if ((dist_delantero_izq < distancia_minima) | (dist_delantero_der < distancia_minima)) {
    if (dist_delantero_izq < dist_delantero_der) {
      timer_old = millis();
      retroceder();
      giro_derecha();
    }
    else {
      timer_old = millis();
      retroceder();
      giro_izquierda();
    }
  } 
  
  // Si los sensores de distancia no detectan obstaculos, vamos hacia adelante!
  // A menos que el coche lleve 15 segundos seguidos sin girar, entonces podria estar detenido y forzamos el giro
  else {
    timer_new = millis();
    if ((timer_new-timer_old)>(tiempo_maximo*1000)) {
      retroceder();
      retroceder();
      giro_izquierda();
      timer_old = millis();
    }
    adelantar();
  }
}
