int led = 2;
int buzzer = 3;
int sensor = 4;
int state = 0;
int val = 0;
void setup() {
  Serial.begin(9600);
  pinMode(led, 1);
  pinMode(buzzer, 1);
  pinMode(sensor, 0);
  Serial.println("Motion Detection");
}

void loop() {
  val = digitalRead(sensor);
  digitalWrite(buzzer, 0);
  digitalWrite(led, 0);
  if (val){
    digitalWrite(led, 1);
    if(!state){
      Serial.println("Motion Detected!");
      digitalWrite(buzzer, 1);
      state = 1;
    }
  }else{
    if(state){
      Serial.println("Motion Stopped.");
      state = 0;
    }
  }
  delay(1000);
}
