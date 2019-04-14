#include <Arduino.h>
#include "blink.h"
#include "morse-code.h"
#include "chars.h"

const int wordsPerMinute = 10;
const String message = "EVERY DAY IS CASPER DAY";

boolean doRunProgram;
String morseCodeForMessage;
int millisecondsPerUnit;

boolean isCharacterValid(char character);
boolean parametersAreValid(int wordsPerMinute, String message);

void setup()
{
  // Open the serial port at 9600 bps
  Serial.begin(9600);
  Serial.println("-- setup start --");

  Serial.print("wordsPerMinute: ");
  Serial.println(wordsPerMinute);

  Serial.print("message: ");
  Serial.println(message);

  doRunProgram = parametersAreValid(wordsPerMinute, message);
  Serial.print("doRunProgram: ");
  Serial.println(doRunProgram);

  if (!doRunProgram)
  {
    return;
  }

  pinMode(LED_BUILTIN, OUTPUT);

  const float secondsPerUnit = 60.0 / (float)(50 * wordsPerMinute);
  millisecondsPerUnit = (int)(secondsPerUnit * 1000.0);

  Serial.print("millisecondsPerUnit: ");
  Serial.println(millisecondsPerUnit);

  morseCodeForMessage = convertToMorseCode(message);
  Serial.print("morseCodeForMessage: ");
  Serial.println(morseCodeForMessage);

  Serial.println("-- setup end --");
}

void loop()
{
  Serial.println("-- loop start --");

  if (!doRunProgram)
  {
    return;
  }

  blinkMessageSpacer(millisecondsPerUnit);

  const int size = morseCodeForMessage.length();
  int i;
  for (i = 0; i < size; i++)
  {
    char code = morseCodeForMessage.charAt(i);

    Serial.print(code);

    switch (code)
    {
    case DOT:
      blinkDot(millisecondsPerUnit);
      blinkDotDashSpacer(millisecondsPerUnit);
      break;

    case DASH:
      blinkDash(millisecondsPerUnit);
      blinkDotDashSpacer(millisecondsPerUnit);
      break;

    case SPACE:
      blinkCharacterSpacer(millisecondsPerUnit);
      break;

    case SLASH:
      blinkWordSpacer(millisecondsPerUnit);
      break;
    }
  }

  Serial.print(NEWLINE);

  Serial.println("-- loop start --");
}

boolean parametersAreValid(int wordsPerMinute, String message)
{
  if (wordsPerMinute < 0)
  {
    return false;
  }

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
  boolean isValidChar = asciiCode == 32 || (asciiCode >= 48 && asciiCode <= 57) || (asciiCode >= 65 && asciiCode <= 90);

  return isValidChar;
}
