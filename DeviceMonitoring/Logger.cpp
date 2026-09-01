#include "Logger.h"
#include <fstream>
#include <ctime>
#include <iomanip>

void Logger::log(std::string message)
{
    std::time_t currentTime = std::time(nullptr);
    std::tm localTime{};

    localtime_s(&localTime, &currentTime);

    std::ofstream logFile("device_log.txt", std::ios::app);

    logFile << "[" << std::put_time(&localTime, "%d-%m-%Y %H:%M:%S") << "] " <<  message << "\n";

    logFile.close();
}