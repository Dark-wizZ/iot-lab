int leds[] = {6,7,8};
int buzzer = 9;

void setup() {
  Serial.begin(9600);
  for(int i=0; i<3; i++)
    pinMode(leds[i], HIGH);
  pinMode(buzzer, HIGH);
  Serial.println("Fire detection");
}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  int range = map(val, 0, 1023, 0, 3);
  for(int i=0; i<3; i++)
    digitalWrite(leds[i], LOW);
  if(!range){
    Serial.println("!!Close Fire!!");
    digitalWrite(buzzer, HIGH);
    digitalWrite(leds[0], HIGH);
  }else if(range==1){
    Serial.println("**Distant Fire**");
    digitalWrite(leds[1], HIGH);
  }else{
    Serial.println("No fire");
    digitalWrite(leds[2], HIGH);
  }
  delay(1000);
}
