int boton1 = 11;
int boton2 = 12;

int dir1=4;
int dir2=9;

int step1=3;
int step2=8;
int ultimavez;

int DelayMotor = 7000;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(boton1,INPUT_PULLUP);
  pinMode(boton2,INPUT_PULLUP);

  pinMode(step1,OUTPUT);
  pinMode(step2,OUTPUT);

  pinMode(dir1,OUTPUT);
  pinMode(dir2,OUTPUT);


  //motor1.setSpeed(50);
  //motor2.setSpeed(50);

  ultimavez=millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  if((digitalRead(boton1) == LOW) && (millis() - ultimavez > 500))
  {
    Serial.println("Mover Motor1");
    Girar(dir1,step1);
    ultimavez=millis();
  }

  if((digitalRead(boton2) == LOW) && (millis() - ultimavez > 500))
  {
    Serial.println("Mover Motor2");
    Girar(dir2,step2);
    ultimavez=millis();
  }

}
void Girar(int dir, int stepp)
{
  digitalWrite(dir,HIGH); // Enables the motor to move in a particular direction
  for(int x = 0; x < 250; x++) {
    digitalWrite(stepp,HIGH); 
    delayMicroseconds(DelayMotor); 
    digitalWrite(stepp,LOW); 
    delayMicroseconds(DelayMotor); 
  }
}

