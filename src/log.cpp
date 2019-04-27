#include <Arduino.h>
#include "log.h"

void PrintLogLevel(LogLevel logLevel);

LogLevel logLevel = Warn;

void SetLogLevel(LogLevel newValue)
{
    logLevel = newValue;
}

void PrintLogLevel(LogLevel level)
{
    switch (level)
    {
    case Trace:
        Serial.print("[TRACE]");
        break;

    case Debug:
        Serial.print("[DEBUG]");
        break;

    case Info:
        Serial.print("[INFO]");
        break;

    case Warn:
        Serial.print("[WARN]");
        break;

    case Error:
        Serial.print("[ERROR]");
        break;

    case Fatal:
        Serial.print("[FATAL]");
        break;
    }
}

void Log(LogLevel level, String message)
{
    if (level < logLevel)
    {
        return;
    }

    PrintLogLevel(level);
    Serial.println(message);
}

void Log(LogLevel level, String name, String value)
{
    if (level < logLevel)
    {
        return;
    }

    PrintLogLevel(level);
    Serial.print(name);
    Serial.print(": ");
    Serial.println(value);
}

void Log(LogLevel level, String name, bool value)
{
    if (level < logLevel)
    {
        return;
    }

    PrintLogLevel(level);
    Serial.print(name);
    Serial.print(": ");
    Serial.println(value);
}

void Log(LogLevel level, String name, int value)
{
    if (level < logLevel)
    {
        return;
    }

    PrintLogLevel(level);
    Serial.print(name);
    Serial.print(": ");
    Serial.println(value);
}

void Log(LogLevel level, String name, float value)
{
    if (level < logLevel)
    {
        return;
    }

    PrintLogLevel(level);
    Serial.print(name);
    Serial.print(": ");
    Serial.println(value);
}

void Log(LogLevel level, String name, char value)
{
    if (level < logLevel)
    {
        return;
    }

    PrintLogLevel(level);
    Serial.print(name);
    Serial.print(": ");
    Serial.println(value);
}

void LogTrace(String message)
{
    Log(Trace, message);
}

void LogTrace(String name, String value)
{
    Log(Trace, name, value);
}

void LogTrace(String name, bool value)
{
    Log(Trace, name, value);
}

void LogTrace(String name, int value)
{
    Log(Trace, name, value);
}

void LogTrace(String name, float value)
{
    Log(Trace, name, value);
}

void LogTrace(String name, char value)
{
    Log(Trace, name, value);
}

void LogDebug(String message)
{
    Log(Debug, message);
}

void LogDebug(String name, String value)
{
    Log(Debug, name, value);
}

void LogDebug(String name, bool value)
{
    Log(Debug, name, value);
}

void LogDebug(String name, int value)
{
    Log(Debug, name, value);
}

void LogDebug(String name, float value)
{
    Log(Debug, name, value);
}

void LogInfo(String message)
{
    Log(Info, message);
}

void LogInfo(String name, String value)
{
    Log(Info, name, value);
}

void LogInfo(String name, bool value)
{
    Log(Info, name, value);
}

void LogInfo(String name, int value)
{
    Log(Info, name, value);
}

void LogInfo(String name, float value)
{
    Log(Info, name, value);
}

void LogInfo(String name, char value)
{
    Log(Info, name, value);
}

void LogWarn(String message)
{
    Log(Warn, message);
}

void LogWarn(String name, String value)
{
    Log(Warn, name, value);
}

void LogWarn(String name, bool value)
{
    Log(Warn, name, value);
}

void LogWarn(String name, int value)
{
    Log(Warn, name, value);
}

void LogWarn(String name, float value)
{
    Log(Warn, name, value);
}

void LogWarn(String name, char value)
{
    Log(Warn, name, value);
}

void LogError(String message)
{
    Log(Error, message);
}

void LogError(String name, String value)
{
    Log(Error, name, value);
}

void LogError(String name, bool value)
{
    Log(Error, name, value);
}

void LogError(String name, int value)
{
    Log(Error, name, value);
}

void LogError(String name, float value)
{
    Log(Error, name, value);
}

void LogError(String name, char value)
{
    Log(Error, name, value);
}

void LogFatal(String message)
{
    Log(Fatal, message);
}

void LogFatal(String name, String value)
{
    Log(Fatal, name, value);
}

void LogFatal(String name, bool value)
{
    Log(Fatal, name, value);
}

void LogFatal(String name, int value)
{
    Log(Fatal, name, value);
}

void LogFatal(String name, float value)
{
    Log(Fatal, name, value);
}

void LogFatal(String name, char value)
{
    Log(Fatal, name, value);
}
