#include <LiquidCrystal.h>
#include <Servo.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
Servo radar;

const int TRIG = 8;
const int ECHO = 9;
const int leds[] = {A1, A2, A3, A4, A5};
const int BUZZER = 11;

void setup() {
  lcd.begin(16, 2);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  radar.attach(10);
  pinMode(BUZZER, OUTPUT);

  for (int i = 0; i < 5; i++) pinMode(leds[i], OUTPUT);

  lcd.print("Szog:");
  lcd.setCursor(0, 1);
  lcd.print("Tav:");
}

long measureDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH, 25000);
  return (duration == 0) ? 0 : duration / 58;
}

int angle = 0;
int step = 1;

void loop() {
  int limit = map(analogRead(A0), 0, 1023, 20, 200);

  angle += step;
  if (angle <= 0 || angle >= 180) step = -step;
  radar.write(angle);
  delay(15);

  long dist = measureDistance();
  if (dist > 250) dist = 0;
  if (dist < 10 && dist > 0) digitalWrite(BUZZER,HIGH);
  else digitalWrite(BUZZER,0);

  lcd.setCursor(6, 0);
  lcd.print(angle);
  lcd.print(" deg  ");

  lcd.setCursor(5, 1);
  lcd.print(dist);
  lcd.print("cm/");
  lcd.print(limit);
  lcd.print("    ");

  for (int i = 0; i < 5; i++) {
    bool active = (angle / 36 == i) && (dist > 0 && dist <= limit);
    digitalWrite(leds[i], active);
  }

  delay(100);
}