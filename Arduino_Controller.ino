#include <Servo.h>

int r;
//'b'5/r/n'

Servo serwoWieza;

void Check(int key, int serialIndex)
{
    if(r == key)
    {
      digitalWrite(serialIndex, HIGH);
    }
    else if(r == (key+1))
    {
      digitalWrite(serialIndex, LOW);
    }
}

void SerwoRuch(int setPos)
{
  serwoWieza.write(setPos);
}

void setup() 
{

  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  //serwo wiezyczka
  serwoWieza.attach(3);
  
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available())
  {
    delay(1);
    r = (Serial.read() - '0');
    Serial.println(r); 
    
    Check(1, 8);
    Check(3, 7);
    Check(5, 6);
    Check(7, 5);

    if(r > 8 && r <= 188)
    {
      SerwoRuch(r);
    }
  }
}
