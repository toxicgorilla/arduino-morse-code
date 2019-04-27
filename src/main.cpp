#include <Arduino.h>

#include "log.h"
#include "blink.h"
#include "morse-code.h"
#include "chars.h"

#define PIN_A13 13;

uint8_t potentiometerPin = PIN_A1;
uint8_t buzzerPin = PIN_A13;
uint8_t redLedPin = PIN2;
uint8_t greenLedPin = PIN3;

boolean isCharacterValid(char character);
boolean parametersAreValid(String message);

String message = "EVERY DAY IS REMI DAY";

boolean doRunProgram;
int index;

void setup()
{
  Serial.begin(9600);
  SetLogLevel(Debug);
  LogTrace("-- setup start --");

  pinMode(buzzerPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);

  LogInfo("message", message);

  doRunProgram = parametersAreValid(message);
  LogDebug("doRunProgram", doRunProgram);

  index = 0;
  LogDebug("index", index);

  if (!doRunProgram)
  {
    LogWarn("Message contains invalid characters. Not running program");

    return;
  }

  LogTrace("-- setup end --");
}

void loop()
{
  LogTrace("-- loop start --");

  if (!doRunProgram)
  {
    return;
  }

  const int potentiometerValue = analogRead(potentiometerPin);
  LogDebug("potentiometerValue", potentiometerValue);

  const int wordsPerMinute = map(potentiometerValue, 0, 1023, 0, 60);
  const float secondsPerUnit = 60.0 / (float)(50 * wordsPerMinute);
  const int millisecondsPerUnit = (int)(secondsPerUnit * 1000.0);
  LogDebug("millisecondsPerUnit", millisecondsPerUnit);

  LogTrace("index", index);

  const char charAtIndex = message.charAt(index);
  LogTrace("charAtIndex", charAtIndex);

  const String morseCodeForCharAtIndex = getMorseCodeForCharacter(charAtIndex);

  int i;
  for (i = 0; i < (int)morseCodeForCharAtIndex.length(); i++)
  {
    const char currentChar = morseCodeForCharAtIndex.charAt(i);
    switch (currentChar)
    {
    case DOT:
      blinkDot(millisecondsPerUnit);
      break;

    case DASH:
      blinkDash(millisecondsPerUnit);
      break;

    case SLASH:
      blinkWordSpacer(millisecondsPerUnit);
      break;

    default:
      break;
    }

    blinkDotDashSpacer(millisecondsPerUnit);
  }

  if (index < (int)message.length() - 1)
  {
    index++;
    blinkCharacterSpacer(millisecondsPerUnit);
  }
  else
  {
    index = 0;
    blinkMessageSpacer(millisecondsPerUnit);
  }

  LogTrace("-- loop end --");
}

boolean parametersAreValid(String message)
{
  const int messageLength = message.length();
  int i;
  for (i = 0; i < messageLength; i++)
  {
    const char character = message.charAt(i);
    boolean isValid = isCharacterValid(character);

    if (!isValid)
    {
      return false;
    }
  }

  return true;
}

boolean isCharacterValid(char character)
{
  const int asciiCode = (int)character;
  boolean isValid = asciiCode == 32 || (asciiCode >= 48 && asciiCode <= 57) || (asciiCode >= 65 && asciiCode <= 90);

  return isValid;
}
