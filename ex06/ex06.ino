#include <DHT.h>
DHT dht(2, 11);
int buzzer = 3;
int led1 = 4;
int led2 = 5;
int led3 = 6;
int pins[] = {3,4,5,6}; 
void setup() {
  Serial.begin(9600);
  for(int i=0; i<4; i++)
    pinMode(pins[i], 1);
  dht.begin();
  Serial.println("Temperature and Humidity program");
}

void loop() {
  delay(2000);
  for(int i=0; i<4; i++)
    digitalWrite(pins[i], 0);
  float h = dht.readHumidity();
  float c = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(c) || isnan(f)){
    Serial.println("Failed to read the sensor");
    digitalWrite(led1, 1);
    return;
  }
  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(c, h, false);

  Serial.println("Humidity: "+String(h)+"% Temperature: "+String(c)+"C ");
  Serial.println(String(f)+"F Heat Index: "+String(hic)+"C "+String(hif)+"F");
  if(c > 30){
    digitalWrite(led2, 1);
    Serial.println("Alert: High Temperature!");
    digitalWrite(buzzer, 1);
  }else{
    digitalWrite(led3, 1);
    Serial.println("Alert: Low Temperature!");
  }
}
