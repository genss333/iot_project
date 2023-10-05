int pingTrig = D1;
int pinEcho = D2;
void setup() {
  Serial.begin(9600);
  pinMode(pingTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
}
void loop() {
  long duration, cm;
  digitalWrite(pingTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pingTrig, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingTrig, LOW);
  duration = pulseIn(pinEcho, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.println(String(cm) + " cm.");
  delay(300);
  if (cm < 20) {
    digitalWrite(D4, HIGH);
    digitalWrite(D5, HIGH);
  } else {
    digitalWrite(D4, LOW);
    digitalWrite(D5, LOW);
  }
}
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}