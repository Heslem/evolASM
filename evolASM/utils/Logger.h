#pragma once
#include <string>

class Logger {
public:
    static void info(const std::string& message);
    static void warn(const std::string& message);
    static void error(const std::string& message);

private:
    static void log(const std::string& level, const std::string& colorCode, const std::string& message);
};