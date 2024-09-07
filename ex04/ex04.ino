int buzzer = 8;
int led1 = 9;
int led2 = 10;
int led3 = 11;
int sensor = A0;
int moisture;

void setup() {
  Serial.begin(9600);
  pinMode(sensor, 0);
  pinMode(led1, 1);
  pinMode(led2, 1);
  pinMode(led3, 1);
  Serial.println("Soil Moisture Program");
}

void loop() {
  int val = analogRead(A0);
  moisture = (100 - ((val/1023.0)*100));
  digitalWrite(led1, 0);
  digitalWrite(led2, 0);
  digitalWrite(led3, 0);
  digitalWrite(buzzer, 0);
  Serial.println("******************************");
  Serial.println("Moisture: "+String(moisture)+"%");
  if(moisture > 60){
    digitalWrite(led1, 1);
    Serial.println("Water Soil");
  }else if(moisture > 40){
    digitalWrite(led2, 1);
    Serial.println("Humid Soil");
  }else if(moisture > 2){
    digitalWrite(led3, 1);
    digitalWrite(buzzer, 1);
    Serial.println("Dry Soil");
  }else{
    Serial.println("Disconnected");
  }
  delay(1000);
}
