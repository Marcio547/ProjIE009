#define trigPin 6
#define echoPin 7


void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int D1;
  // put your main code here, to run repeatedly:
  D1 = calc_distance();

  //Serial.println(D1); //check on arduino
  Serial.write(D1); //Send to octave
  delay(100);
}


int calc_distance(){
  float duration, distance,distance100;

  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = (duration/2) / 29.1;
  distance100 = 100*(duration/2) / 29.1;

  //return distance100;
  return distance;
}
