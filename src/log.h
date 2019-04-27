#include <Arduino.h>

#ifndef GLOBAL_LogLevel

#define GLOBAL_LogLevel

enum LogLevel
{
    Trace = 0,
    Debug = 1,
    Info = 2,
    Warn = 3,
    Error = 4,
    Fatal = 5
};

#endif

void SetLogLevel(LogLevel newValue);

void Log(LogLevel level, String message);
void Log(LogLevel level, String name, String value);
void Log(String name, bool value);
void Log(String name, int value);
void Log(String name, float value);
void Log(String name, char value);

void LogTrace(String message);
void LogTrace(String name, String value);
void LogTrace(String name, bool value);
void LogTrace(String name, int value);
void LogTrace(String name, float value);
void LogTrace(String name, char value);

void LogDebug(String message);
void LogDebug(String name, String value);
void LogDebug(String name, bool value);
void LogDebug(String name, int value);
void LogDebug(String name, float value);
void LogDebug(String name, char value);

void LogInfo(String message);
void LogInfo(String name, String value);
void LogInfo(String name, bool value);
void LogInfo(String name, int value);
void LogInfo(String name, float value);
void LogInfo(String name, char value);

void LogWarn(String message);
void LogWarn(String name, String value);
void LogWarn(String name, bool value);
void LogWarn(String name, int value);
void LogWarn(String name, float value);
void LogWarn(String name, char value);

void LogError(String message);
void LogError(String name, String value);
void LogError(String name, bool value);
void LogError(String name, int value);
void LogError(String name, float value);
void LogError(String name, char value);

void LogFatal(String message);
void LogFatal(String name, String value);
void LogFatal(String name, bool value);
void LogFatal(String name, int value);
void LogFatal(String name, float value);
void LogFatal(String name, char value);
