#include <Ultrasonic.h>
#include <RunningMedian.h>

RunningMedian Median50 = RunningMedian(50);

int sensorpin = 0;  // analog pin used to connect the sharp sensor
float val = 0; 
float distance;

const int numberOfEntries = 20;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  for (int i=0; i < numberOfEntries; i++)
  {
    val = analogRead(sensorpin);
    Median50.add(val);
    delay(5);
  } 
  
  distance = 2400/(val - 20);
  
  float a50 = 2400/(Median50.getAverage()-20);
   
  Serial.print(distance); Serial.print("-");
  Serial.println(a50);
}
