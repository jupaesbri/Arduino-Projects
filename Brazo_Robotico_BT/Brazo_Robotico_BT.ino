#include <Servo.h>

// pines PWM  3 5 6 9 10

//Inicializamos los servomotores
Servo myservo1;  
Servo myservo2;
Servo myservo3;
Servo myservo4;
Servo myservo5;

//Inicializamos la posicion de cada motor y la variable de datos
int pos1=100;
int pos2=50;
int pos3=70;
int pos4=50;
int pos5=120;
char dato=' ';

void setup() {
  //Fijamos los servos a sus salidas
  myservo1.attach(3);
  myservo2.attach(5);
  myservo3.attach(6);
  myservo4.attach(9);
  myservo5.attach(10);

  //Inicializamos el puerto serial para el Bluetooth
  Serial.begin(9600);

  //Posicionamos los motores en la posicion inicial
  myservo1.write(100);
  myservo2.write(50);
  myservo3.write(70);
  myservo4.write(50);
  myservo5.write(120);
}

void loop() {
  if(Serial.available()>0)
  {
    dato=Serial.read();
  }

  if(dato == '1')
  {
    if(pos1<180)
    {
      pos1=pos1+1;
      Serial.println("Motor 1 Izquierda");
      myservo1.write(pos1);
    }
  }

  if(dato == '2')
  {
    if(pos1>0)
    {
      pos1=pos1-1;
      Serial.println("Motor 1 Derecha");
      myservo1.write(pos1);
    }
  }

  if(dato == '3')
  {
    if(pos2<180)
    {
      pos2=pos2+1;
      Serial.println("Motor 2 Izquierda");
      myservo2.write(pos2);
    } 
  }

  if(dato == '4')
  {
    if(pos2>0)
    {
      pos2=pos2-1;
      Serial.println("Motor 2 Derecha");
      myservo2.write(pos2);
    } 
  }

  if(dato == '5')
  {
    if(pos3<180)
    {
      pos3=pos3+1;
      Serial.println("Motor 3 Izquierda");
      myservo3.write(pos3);
    } 
  }

  if(dato == '6')
  {
    if(pos3>0)
    {
      pos3=pos3-1;
      Serial.println("Motor 3 Derecha");
      myservo3.write(pos3);
    } 
  }

  if(dato == '7')
  {
    if(pos4<180)
    {
      pos4=pos4+1;
      Serial.println("Motor 4 Izquierda");
      myservo4.write(pos4);
    } 
  }

  if(dato == '8')
  {
    if(pos4>0)
    {
      pos4=pos4-1;
      Serial.println("Motor 4 Derecha");
      myservo4.write(pos4);
    } 
  }

  if(dato == '9')
  {
    if(pos5<180)
    {
      pos5=pos5+1;
      Serial.println("Motor 5 Izquierda");
      myservo5.write(pos5);
    } 
  }

  if(dato == '0')
  {
    if(pos5>0)
    {
      pos5=pos5-1;
      Serial.println("Motor 5 Derecha");
      myservo5.write(pos5);
    } 
  }

  if(dato == 'S')
  {
    //Serial.println("Detener Todo");
  }
}

