#include <stdlib.h>
#include <stdio.h>


#define MAX 50

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

int i =0;
float num=1.45;
String data = String(num),teste;
char buf[MAX],start_seq = '^',end_seq = '_'; 
// '^' = 94
// '_' = 95
void loop() {
  
  // put your main code here, to run repeatedly:
  //while(i < 100)

  
//    while(1){
//      c = '^'
//      Serial.write(c);
//      if(
//      Serial.print(data);
//      i++;
//    }
  String teste = to_string(num);
}
