
void setup() {
  Serial.begin(9600);
  pinMode(2, 0);
}

void loop() {
  Serial.println(digitalRead(2));
}
