    /*
    * Kalman Filter for HC SR04 - idea validation
      Improvement for AirAccordion Project
      Created By Marcio Albano Hermelino Ferreira
    */
    
    
    
    // HC SR04 pin definition
    const int trigPin = 6;
    const int echoPin = 7;
    
    
    //Use of 3 LEDs (Red, Green and Blue to check if the bellows are being pressed or expanded
    
    const int plusLed = 8;
    const int minusLed = 9;
    const int zeroLed = 10;
    
    //distance measurements
    int d1=0;
    int d2=0;
    int d3=0;
    int t1=0;
    int t2=0;
    
    //distance difference measurements
    int dif=0;
    int dif2=0;

    //global variables for distance calculation
    long duration;
    int distance;
    
    
    void setup() {
    
      //LED pins initialization  
      pinMode(plusLed, OUTPUT);  // GREEN 
      pinMode(minusLed, OUTPUT); // RED
      pinMode(zeroLed, OUTPUT);  // BLUE
      
      //HC SR04 Pin initialization
      pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
      pinMode(echoPin, INPUT); // Sets the echoPin as an Input
      Serial.begin(115200); // Starts the serial communication
    }
    
    
    void loop() {
      //main program
    
      //distance calculation for the first instant
      //t1 =millis();
      d1 = calc_distance();
      //Serial.print("Distance[t] ");
      //Serial.println(d1);
      //t2=millis();
      //distance calculation for the second instant
      //d2  = calc_distance();
      
      //Serial.print("Distance[t+1]: ");
      //Serial.println(d2);
      //delay(5);
    
      //distance calculation for a third instant
      //d3  = calc_distance();
    
      //distant differences calculations
      dif  = d2-d1;
      dif2 = d3-d1;
      //Serial.print("Variation d2-d1: ");
      //Serial.println(dif);
    
      //Serial.print("dif2: ");
      //Serial.println(dif);

      
      //Bellows Expansion: Lights up GREEN LED
//      if(1){
//        digitalWrite(plusLed, HIGH);
//        digitalWrite(minusLed,LOW);
//        digitalWrite(zeroLed, LOW);
//      }
//      //Bellows Compression: Lights up GREEN LED
//      //lse
//      if(1){
//        digitalWrite(plusLed, LOW);
//        digitalWrite(minusLed,HIGH);
//        digitalWrite(zeroLed, LOW);
//      }
//    
//      //No movement: Lights up BLUE LED
//      //else if(dif2 >-100 &&  dif2 <=100 && dif2 ==0){
//      if(1){
//        digitalWrite(plusLed, LOW);
//        digitalWrite(minusLed,LOW);
//        digitalWrite(zeroLed, HIGH);
//      }

    }
    
    
    int calc_distance(){
      
      int d_mm;
      //sensor reading at some time instant
      // Clears the trigPin
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      // Sets the trigPin on HIGH state for 10 micro seconds
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      // Reads the echoPin, returns the sound wave travel time in microseconds
      
      duration = pulseIn(echoPin, HIGH
      // Calculating the distance
    
      // sound velocity = 343 m/s
      // divided by 2 because the pulse walks twice the distance.
      distance= duration*0.0343/2;
    
      //measurement with more accuracy
      d_mm = distance*100;
      //dser = 0x00 + distance;
      //d_hex = String(distance,HEX);
      //Serial.print('+');
      //Serial.write(distance);
      //Serial.print("+",DEC);
      //Serial.write('\n');
      
      //Serial.write(d_mm);
      //Serial.println(distance);
      Serial.println(distance);
    return d_mm;
    
    }
      
      
