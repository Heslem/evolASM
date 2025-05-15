#include "Logger.h"
#include <iostream>

// ANSI escape color codes
#define COLOR_WHITE   "\033[37m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_RED     "\033[31m"
#define COLOR_RESET   "\033[0m"

void Logger::log(const std::string& level, const std::string& colorCode, const std::string& message) {
    std::cout << colorCode << "[" << level << "] " << message << COLOR_RESET << std::endl;
}

void Logger::info(const std::string& message) {
    log("INFO", COLOR_WHITE, message);
}

void Logger::warn(const std::string& message) {
    log("WARN", COLOR_YELLOW, message);
}

void Logger::error(const std::string& message) {
    log("ERROR", COLOR_RED, message);
}
