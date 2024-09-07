#include <DHT.h>
DHT dht(2, 11);
int buzzer = 3;
int leds[] = {4,5,6};
void setup() {
  Serial.begin(9600);
  for(int i=0; i<3; i++)
    pinMode(leds[i], 1);
  pinMode(buzzer, 1);
  dht.begin();
  Serial.println("Temperature and Humidity program");
}

void loop() {
  delay(2000);
  for(int i=0; i<3; i++)
    digitalWrite(leds[i], 0);
  digitalWrite(buzzer, 0);
  float h = dht.readHumidity();
  float c = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(c) || isnan(f)){
    Serial.println("Failed to read the sensor");
    digitalWrite(leds[0], 1);
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(c, h, false);

  Serial.println("Humidity: "+String(h)+"% Temperature: "+String(c)+"C ");
  Serial.println(String(f)+"F Heat Index: "+String(hic)+"C "+String(hif)+"F");
  if(c > 30){
    digitalWrite(leds[1], 1);
    Serial.println("Alert: High Temperature!");
    digitalWrite(buzzer, 1);
  }else{
    digitalWrite(leds[2], 1);
    Serial.println("Alert: Low Temperature!");
  }
}
