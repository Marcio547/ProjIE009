void setup(){
  Serial.begin(115200);
}

void loop(){
  Serial.write(10,HEX); // send a byte with the value 45

   //int bytesSent = Serial.write("1"); //send the string "hello" and return the length of the string.
}
