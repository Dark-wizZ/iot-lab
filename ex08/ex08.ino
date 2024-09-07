int leds[] = {6,7,8};
int buzzer = 9;

void setup() {
  Serial.begin(9600);
  for(int i=0; i<3; i++)
    pinMode(leds[i], 1);
  pinMode(buzzer, 1);
  Serial.println("Fire detection");
}

void loop() {
  int val = analogRead(A0);
  Serial.println(val);
  int range = map(val, 0, 1023, 0, 3);
  for(int i=0; i<3; i++)
    digitalWrite(leds[i], 0);
  if(!range){
    Serial.println("!!Close Fire!!");
    digitalWrite(buzzer, 1);
    digitalWrite(leds[0], 1);
  }else if(range==1){
    Serial.println("**Distant Fire**");
    digitalWrite(leds[1], 1);
  }else{
    Serial.println("No fire");
    digitalWrite(leds[2], 1);
  }
  delay(1000);
}
