int led = 2;
int buzzer = 3;
int sensor = 4;
int state = 0;
int val = 0;
void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.println("Motion Detection");
}

void loop() {
  val = digitalRead(sensor);
  digitalWrite(buzzer, LOW);
  digitalWrite(led, LOW);
  if (val){
    digitalWrite(led, HIGH);
    if(!state){
      Serial.println("Motion Detected!");
      digitalWrite(buzzer, HIGH);
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
