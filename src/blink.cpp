#include <Arduino.h>
#include "blink.h"

void blinkDot(int millisecondsPerUnit)
{
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(2, HIGH);
  tone(13, 440);

  delay(millisecondsPerUnit);
}

void blinkDash(int millisecondsPerUnit)
{
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(3, HIGH);
  tone(13, 440);

  delay(millisecondsPerUnit * 3);
}

void blinkDotDashSpacer(int millisecondsPerUnit)
{
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  noTone(13);

  delay(millisecondsPerUnit);
}

void blinkCharacterSpacer(int millisecondsPerUnit)
{
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  noTone(13);

  delay(millisecondsPerUnit * 3);
}

void blinkWordSpacer(int millisecondsPerUnit)
{
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  noTone(13);

  delay(millisecondsPerUnit * 7);
}

void blinkMessageSpacer(int millisecondsPerUnit)
{
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(2000);
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  delay(2000);
}