int led = 3;
int threshold = 900;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  if(val>800)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
  delay(500);
}
