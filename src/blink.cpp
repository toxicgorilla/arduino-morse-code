#include <Arduino.h>
#include "blink.h"
#include "log.h"

extern uint8_t buzzerPin;
extern uint8_t redLedPin;
extern uint8_t greenLedPin;

void blinkDot(int millisecondsPerUnit, int frequency)
{
  LogDebug("blinkDot");

  digitalWrite(redLedPin, HIGH);
  tone(buzzerPin, frequency);

  delay(millisecondsPerUnit);
}

void blinkDash(int millisecondsPerUnit, int frequency)
{
  LogDebug("blinkDash");

  digitalWrite(greenLedPin, HIGH);
  tone(buzzerPin, frequency);

  delay(millisecondsPerUnit * 3);
}

void blinkDotDashSpacer(int millisecondsPerUnit)
{
  LogDebug("blinkDotDashSpacer");

  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  noTone(buzzerPin);

  delay(millisecondsPerUnit);
}

void blinkCharacterSpacer(int millisecondsPerUnit)
{
  LogDebug("blinkCharacterSpacer");

  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  noTone(buzzerPin);

  delay(millisecondsPerUnit * 3);
}

void blinkWordSpacer(int millisecondsPerUnit)
{
  LogDebug("blinkWordSpacer");

  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  noTone(buzzerPin);

  delay(millisecondsPerUnit * 7);
}

void blinkMessageSpacer(int millisecondsPerUnit)
{
  LogDebug("blinkMessageSpacer");

  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  delay(200);
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, HIGH);
  delay(1000);
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, LOW);
  delay(200);
}