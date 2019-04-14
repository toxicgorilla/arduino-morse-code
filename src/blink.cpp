#include <Arduino.h>
#include "blink.h"

void blinkDot(int millisecondsPerUnit)
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(millisecondsPerUnit);
}

void blinkDash(int millisecondsPerUnit)
{
  digitalWrite(LED_BUILTIN, HIGH);
  delay(millisecondsPerUnit * 3);
}

void blinkDotDashSpacer(int millisecondsPerUnit)
{
  digitalWrite(LED_BUILTIN, LOW);
  delay(millisecondsPerUnit);
}

void blinkCharacterSpacer(int millisecondsPerUnit)
{
  digitalWrite(LED_BUILTIN, LOW);
  delay(millisecondsPerUnit * 3);
}

void blinkWordSpacer(int millisecondsPerUnit)
{
  digitalWrite(LED_BUILTIN, LOW);
  delay(millisecondsPerUnit * 7);
}

void blinkMessageSpacer(int millisecondsPerUnit)
{
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(2000);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(2000);
  digitalWrite(LED_BUILTIN, LOW);
}