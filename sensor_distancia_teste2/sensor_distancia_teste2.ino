/*
HC-SR04 Ping distance sensor]
Teste do sensor de distancia
*/

#include <stdlib.h>

#define trigPin 6
#define echoPin 7
#define MAX 3
int T1,T2;
long D1,D2;
char buf[MAX];

void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  /*T1 = millis();
  
  //Serial.write(D1);
  //Serial.println(D1);
  delay(50);
  //D2 = calc_distance();
  T2 = millis();
  //Serial.write(D2);
  dif1 = D2-D1;
  //Serial.write(abs(D2-D1));
  //Serial.println(D1);
  */
  D1 = calc_distance();
  //Serial.println(D1);
  t1 = millis();

  Serial.print('_'); //95
  Serial.print(D1);
  Serial.print('^'); //94
  //Serial.write(D1*100);
  //Serial.write('_');
  //Serial.write('^');
} 



float calc_distance(){
  float duration, distance, distance_mm;
  float d_mm;



  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  d_mm = ((duration/2) / 29.1)*10;
  //distance = round((duration/2) / 29.1);
  distance = (duration/2) / 29.1;
  distance_mm = d_mm;
//  if (distance >= 200 || distance <= 0){
//    Serial.println("Out of range");
//  }
//  else {
//    //Serial.println(distance_mm);
//    //Serial.println(" mm");
//    Serial.write(distance);
//  }
  delay(10);

  //Serial.println(t2-t1);
  //Serial.println(distance*100);
  return distance*100;

}
