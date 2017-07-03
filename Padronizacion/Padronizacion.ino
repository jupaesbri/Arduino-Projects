//Agregamos la libreria y creamos las variables tipo Servo
#include <VarSpeedServo.h>

VarSpeedServo servo;
VarSpeedServo servo2;
VarSpeedServo servo3;

VarSpeedServo servo4;
VarSpeedServo servo5;
VarSpeedServo servo6;
                        
#define BUZZER  10      // buzzer pin
#define MIN_BPM 20      // minimo valor bpm
#define MAX_BPM 240     // maximo valor bpm

int bpm;                // valor bpm
int cont =0;

bool direccion=false;
bool paso=false;

int entrada=0;
bool but_status = false;
bool leyo= false;

int uno=0;
int dos=0;
int total=0;

void setup() {
  Serial.begin(9600);       // comienza la comunicacion serial
  pinMode(BUZZER, OUTPUT);  // inicializamos a buzzer como salida
  //leemos el valor de frecuencia
  while(!leyo)
  {
    if(Serial.available()>=2)
    {
      //leemos uno a uno los digitos enviados
      uno=Serial.read();
      delay(10);
      dos=Serial.read();
      leyo=true;
    }
  }
  transformamos a entero
  bpm=(uno-48)*10 + (dos-48);
  //Serial.println(bpm);
  
  
  //adjuntamos los servos a sus salidas pwm
  servo.attach(2);
  servo2.attach(3);
  servo3.attach(4);

  servo4.attach(5);
  servo5.attach(6);
  servo6.attach(7);
  
  // inicializa la posicion
  servo.write(179,255,true);
  servo2.write(179,255,true);
  servo3.write(179,255,true);
  
  servo4.write(0,255,true);
  servo5.write(0,255,true);
  servo6.write(0,255,true);// set the intial position of the servo, as fast as possible, wait until done
  //delay(3000);
}

void loop() {
  //leee el valor del serial para saber si ya mando a comenzar
  if(Serial.available() > 0)
  {
    entrada = Serial.read();
    if(entrada == 49)
    {
      Button();
    } 
  }
  if(but_status == 1)
  {
    if(cont==2)
    {
      tone(BUZZER,1000); //toca el bip tercero
      cont=0;
    }
    else
    {
      tone(BUZZER, 2000);       // toca el bip en un tono
      cont++; 
    }
      
    delay(6000 / bpm);        // 10% del tiempo de bpm calculado en un segundo (60000)
    noTone(BUZZER);           // silencia el buzzer
    
    if(direccion == false)
    {
      if(!paso)
      {
        paso=true;
        servo.write(90,255,false);
        servo2.write(90,255,false);
        servo3.write(90,255,false);
        
        servo4.write(90,255,false);
        servo5.write(90,255,false);
        servo6.write(90,255,false);
        
      }
      else
      {
        paso=false;
        direccion= true;
      }
    }
    else
    {
      direccion = false;
      servo.write(179,255,false);      
      servo2.write(179,255,false);
      servo3.write(179,255,false);

      servo4.write(0,255,false);      
      servo5.write(0,255,false);
      servo6.write(0,255,false);

    }
    delay(54000 / bpm);       // 90% de tiempo calculado en un segundo (54000)
  }
}

void Button()
{
  but_status = !but_status;  
  delay(30);                
  cont=0;
  paso=false;
  direccion=false;
  if(but_status == 0)        
  {
    noTone(BUZZER);
  }    
}

