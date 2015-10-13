#include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
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
// int LED_PIN = 4;
// int IR_PIN = 5;
// IRrecv irrecv(IR_PIN);
// decode_results IR_resultados;

// Crear el objeto del driver de motores
Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 

// Instanciar los motores
// Adafruit_DCMotor *myMotorLeft = AFMS.getMotor(1);
// Adafruit_DCMotor *myMotorLeft = AFMS.getMotor(2);
Adafruit_DCMotor *myMotorRight = AFMS.getMotor(1);
Adafruit_DCMotor *myMotorLeft = AFMS.getMotor(2);

// Distancia minima detectada por los sensores de distancia para girar, medida en centimetros
int distancia_minima = 15;

// Temporizador
unsigned long timer_new;
unsigned long timer_old;

// Tiempo maximo en segundos para forzar giro si no ha girado solo
int tiempo_maximo = 10;

// Tiempo en milisegundos de giro
int delay_giro = 250;

//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
// NOTA: El chip HC-06 funciona perfectamente conectandolo al pin de alimentacion de 3.3v, sin necesidad de convertir la tension
SoftwareSerial BT(8,9); //8 RX, 9 TX.


