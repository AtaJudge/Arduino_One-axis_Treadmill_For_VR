#include <Joystick.h>

float Val=0;
float Count=0;
int Rpm;
int Oldtime=0;
int time;
Joystick_ ZevkCubugu;

void isr()
{
  Count++;
}

void setup()
{
  ZevkCubugu.begin();
  ZevkCubugu.setXAxisRange(0,250);
  Serial.begin(9600);
  attachInterrupt(1,isr,RISING);
}

void loop()
{
  delay(1000);
  detachInterrupt(0);
  time=millis()-Oldtime;
  Rpm=(Count/time)*30000;
  Serial.print("RPM: ");
  Serial.println(Rpm);
  ZevkCubugu.setXAxis(Rpm);
  Oldtime=millis();
  Count=0;
  attachInterrupt(1,isr,RISING);
}
