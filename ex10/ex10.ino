int led = 2;
void setup() {
  Serial.begin(9600);
  pinMode(led, 1);
}

void loop() {
  int val = analogRead(A0);
  Serial.println("Sensor: "+String(val));
  if(val > 890) digitalWrite(led, 1);
  else digitalWrite(led, 0);
  delay(1000);
}
