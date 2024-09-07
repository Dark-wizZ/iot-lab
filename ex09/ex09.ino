int led = 2;
int threshold = 600;
void setup() {
  Serial.begin(9600);
  pinMode(led, 1);
}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  if(val>threshold)
    digitalWrite(led, 1);
  else:
    digitalWrite(led, 0);
  delay(500);
}
