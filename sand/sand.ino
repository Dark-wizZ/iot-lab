int r = 9;
int g = 10;
int b = 11;
void setup(){
  Serial.begin(9600);
  pinMode(r, 1);
  pinMode(g, 1);
  pinMode(b, 1);
}
void loop(){
  analogWrite(r, map(analogRead(A0), 0, 1023, 0, 255));
  analogWrite(g, 255);
  analogWrite(b, 255);

}
