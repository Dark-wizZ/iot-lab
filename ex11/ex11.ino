
void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(A0);
  Serial.println("Force sensor reading: "+String(val));
  if(val < 10) Serial.println("No pressure");
  else if(val < 200) Serial.println("Light touch");
  else if(val < 500) Serial.println("Light pressure");
  else if(val < 800) Serial.println("Medium pressure");
  else Serial.println("Heavy pressure");
  delay(500);
}
