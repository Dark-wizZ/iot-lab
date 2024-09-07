int s[] = {8, 9, 10, 11};
int out = 12;
int color[4]; //red, blue, clear, green
void setup() {
  Serial.begin(9600);
  for(int i=0; i<4; i++)
    pinMode(s[i], 1);
    pinMode(out, 0);
    digitalWrite(s[0], 1);
    digitalWrite(s[1], 1);
}

void loop() {
  int c=0;
  for(int i=0; i<2; i++)
    for(int j=0; j<2; j++)
      color[c++] = pulseIn(out, LOW);
  Serial.println("Red: "+String(color[0])+"\tBlue: "+
  String(color[1]) +"\tGreen: "+String(color[2]));
  delay(2000);
}
