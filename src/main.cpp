#include <Arduino.h>

#include <Arduino.h>

// Піни
#define LDR_PIN 4
#define RELAY_PIN 5

// Пороги освітленості
#define THRESHOLD_DARK 1500
#define THRESHOLD_LIGHT 2000

void setup()
{
  Serial.begin(115200);

  pinMode(LDR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
}

void loop()
{
  // 1. Зчитуємо значення ADC
  int adcValue = analogRead(LDR_PIN);

  // 2. Порівнюємо з порогами
  if (adcValue < THRESHOLD_DARK)
  {
    digitalWrite(RELAY_PIN, HIGH);
  }
  else if (adcValue > THRESHOLD_LIGHT)
  {
    digitalWrite(RELAY_PIN, LOW);
  }

    Serial.print("ADC: ");
  Serial.println(adcValue);

  delay(200);
}
