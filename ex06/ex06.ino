#include <DHT.h>
DHT dht(2, 11);
int buzzer = 3;
int leds[] = {4,5,6};
void setup() {
  Serial.begin(9600);
  for(int i=0; i<3; i++)
    pinMode(leds[i], OUTPUT);
  pinMode(buzzer, OUTPUT);
  dht.begin();
  Serial.println("Temperature and Humidity program");
}

void loop() {
  delay(2000);
  for(int i=0; i<3; i++)
    digitalWrite(leds[i], LOW);
  digitalWrite(buzzer, LOW);
  float h = dht.readHumidity();
  float c = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(c) || isnan(f)){
    Serial.println("Failed to read the sensor");
    digitalWrite(leds[0], HIGH);
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(c, h, false);

  Serial.println("Humidity: "+String(h)+"% Temperature: "+String(c)+"C ");
  Serial.println(String(f)+"F Heat Index: "+String(hic)+"C "+String(hif)+"F");
  if(c > 30){
    digitalWrite(leds[1], HIGH);
    Serial.println("Alert: High Temperature!");
    digitalWrite(buzzer, HIGH);
  }else{
    digitalWrite(leds[2], HIGH);
    Serial.println("Alert: Low Temperature!");
  }
}
