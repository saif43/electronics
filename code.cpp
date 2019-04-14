#include <Servo.h>

Servo servo1;
Servo servo2;

int motor1 = 0;
int motor2 = 0;

void setup()
{
  pinMode(11, OUTPUT);

  pinMode(4, OUTPUT); //F
  pinMode(5, OUTPUT); //G
  pinMode(6, OUTPUT); //A
  pinMode(7, OUTPUT);//B
  pinMode(8, OUTPUT);//C
  pinMode(9, OUTPUT);//D
  pinMode(10, OUTPUT);//E

  pinMode(A5, OUTPUT); // Red1
  pinMode(A4, OUTPUT); // Yellow1
  pinMode(A3, OUTPUT); // Green1

  pinMode(A2, OUTPUT); // Red2
  pinMode(A1, OUTPUT); // Yellow2
  pinMode(A0, OUTPUT); // Green2

}

void loop()
{

  servo2.attach(3);

  digitalWrite(A3, HIGH); // Green1
  digitalWrite(A2, HIGH); // Red2

  ssOff();
  motor2Run();
  servo2.detach();
  delay(7000);

  digitalWrite(A3, LOW); // Green1
  digitalWrite(A4, HIGH); // Yellow1

  sevenSegment();
  ssOff();
  servo2.attach(3);
  motor2Rev();
  servo2.detach();

  digitalWrite(A4, LOW); // Yellow1
  digitalWrite(A2, LOW); // Red2

  servo1.attach(2);

  digitalWrite(A5, HIGH); // Red1
  digitalWrite(A0, HIGH); // Green2

  motor1Run();
  servo1.detach();
  delay(7000);

  digitalWrite(A0, LOW); // Green2
  digitalWrite(A1, HIGH); // Yellow2

  sevenSegment();
  ssOff();
  servo1.attach(2);
  motor1Rev();
  servo1.detach();

  digitalWrite(A1, LOW); // Yellow2
  digitalWrite(A5, LOW); // Red1
}


void motor2Run()
{
  for (motor2 = 0; motor2 <= 150; motor2 += 1)
  {
    servo2.write(motor2);
    delay(5);
  }
}
void motor2Rev()
{
  for (motor2 = 150; motor2 >= 0; motor2 -= 1)
  {
    servo2.write(motor2);
    delay(5);
  }
}
void motor1Run()
{
  for (motor1 = 0; motor1 <= 150; motor1 += 1)
  {
    servo1.write(motor1);
    delay(5);
  }
}
void motor1Rev()
{
  for (motor1 = 150; motor1 >= 0; motor1 -= 1)
  {
    servo1.write(motor1);
    delay(5);
  }
}


void sevenSegment()
{
  nine();
  eight();
  seven();
  six();
  five();
  four();
  three();
  two();
  one();
  zero();

}

void ssOff()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, HIGH);  //1

}

void zero()
{
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);  //0

  buzz(11, 2500, 250);

}
void one()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);  //1

  buzz(11, 2500, 250);

}
void two()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, HIGH);  //2

  buzz(11, 2500, 250);

}
void three()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);  //3

  buzz(11, 2500, 250);

}
void four()
{
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);  //4

  delay(250);
}
void five()
{
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);  //5

  delay(250);
}
void six()
{
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);  //6

  delay(250);

}
void seven()
{
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(8, LOW);  //7

  delay(250);


}
void eight()
{
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, LOW);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);  //8

  delay(250);

}
void nine()
{
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);  //9

  delay(250);
}

void buzz(int targetPin, long frequency, long length)
{
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++)
  { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait againf or the calculated delay value
  }
}