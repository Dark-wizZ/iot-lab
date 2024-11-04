int buzzer = 8;
int leds[] = {9, 10, 11};
int moisture;

void setup() {
  Serial.begin(9600);
  for(int i=0; i<3; i++)
    pinMode(leds[i], OUTPUT);
  Serial.println("Soil Moisture Program");
}

void loop() {
  int val = analogRead(A0);
  moisture = map(val, 0, 1023, 100, 0);
  for (int i=0; i<3; i++)
    digitalWrite(leds[i], LOW);
  digitalWrite(buzzer, LOW);
  Serial.println("******************************");
  Serial.println("Moisture: "+String(moisture)+"%");
  if(moisture > 60){
    digitalWrite(leds[0], HIGH);
    Serial.println("Water Soil");
  }else if(moisture > 40){
    digitalWrite(leds[1], HIGH);
    Serial.println("Humid Soil");
  }else if(moisture > 2){
    digitalWrite(leds[3], HIGH);
    digitalWrite(buzzer, HIGH);
    Serial.println("Dry Soil");
  }else{
    Serial.println("Disconnected");
  }
  delay(1000);
}
