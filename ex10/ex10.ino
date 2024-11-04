int led = 2;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int val = analogRead(A0);
  Serial.println("Sensor: "+String(val));
  if(val > 890) digitalWrite(led, HIGH);
  else digitalWrite(led, LOW);
  delay(1000);
}
