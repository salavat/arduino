#include <RunningMedian.h>

RunningMedian Median50 = RunningMedian(30); // Медианный фильтр на исходные данные - вольты
RunningMedian Median50_2 = RunningMedian(30); // Медианный фильтр на сантиметры

int sensorpin = 0;  // Номер аналогового входа в ардуино
float val = 0;      // Переменная для чтения исх. данных с сенсора 
float distance;     // Переменная для расчета дистанции в см 
float distance_filtered; // Переменная для расчета дистанции в см с фильтром 1
float distance_filtered2;// Переменная для расчета дистанции в см с фильтром 2

const int numberOfEntries = 20;

void setup() {
  Serial.begin(9600);
}

void loop() {
   
   for (int i=0; i < numberOfEntries; i++)
    {
      val = analogRead(sensorpin); // Добавляем в фильтр исходные данные - вольты
      Median50.add(val);
      delay(15);
    } 
    
  distance = 13*pow(val*0.0048828125, -1) ;
  Median50_2.add(distance); // Добавляем в фильтр сантиметры
  
  distance_filtered  = 13*pow(Median50.getAverage()*0.0048828125, -1);
  distance_filtered2 = Median50_2.getAverage();
   
  Serial.print(distance); Serial.print("-");
  Serial.print(distance_filtered);Serial.print("-");
  Serial.println(distance_filtered2);
}
