#include "Device.h"
#include <iostream>

Device::Device(std::string deviceName, int deviceId)
{
    name = deviceName;
    id = deviceId;

    temperature = 0;
    voltage = 0;
    current = 0;
    isOnline = true;
    errorCode = NO_ERROR;
}

std::string Device::getName()
{
    return name;
}

int Device::getId()
{
    return id;
}

void Device::setTemperature(double newTemp) 
{
    temperature = newTemp;
}

double Device::getTemperature()
{
    return temperature;
}

void Device::setVoltage(double newVolt)
{
    voltage = newVolt;
}

double Device::getVoltage()
{
    return voltage;
}

void Device::setCurrent(double newCurr)
{
    current = newCurr;
}

double Device::getCurrent() {
    return current;
}

void Device::setIsOnline(bool newStatus)
{
    isOnline = newStatus;
}

bool Device::getIsOnline()
{
    return isOnline;
}

ErrorCode Device::getErrorCode()
{
    return errorCode;
}

bool Device::isTemperatureHigh()
{
    if (temperature > 80)
    {
        return true;
    }
    else
    {
        return false;

    }
}

bool Device::isVoltageNormal()
{
    if (voltage >= 1 && voltage <= 1.4)
    {
        return true;
    }
    else
    {
        return false;

    }
}

bool Device::isCurrentNormal()
{
    if (current >= 0.5 && current <= 3.0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

std::string Device::getErrorMessage()
{
    switch (errorCode)
    {
    case NO_ERROR:
        return "No Error";

    case TEMPERATURE_ERROR:
        return "Temperature Error";

    case VOLTAGE_ERROR:
        return "Voltage Error";

    case CURRENT_ERROR:
        return "Current Error";

    case DEVICE_OFFLINE:
        return "Device is Offline";

    default:
        return "Unknown Error";
    }
}

void Device::runDiagnostics()
{
    if (!isOnline)
    {
        errorCode = DEVICE_OFFLINE;
    }
    else if (isTemperatureHigh())
    {
        errorCode = TEMPERATURE_ERROR;
    }
    else if (!isVoltageNormal())
    {
        errorCode = VOLTAGE_ERROR;
    }
    else if (!isCurrentNormal())
    {
        errorCode = CURRENT_ERROR;
    }
    else
    {
        errorCode = NO_ERROR;
    }
}

void Device::printStatus()
{
    std::cout << "Device: " << name << "\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Temperature: " << temperature << " C\n";
    std::cout << "Voltage: " << voltage << " V\n";
    std::cout << "Current: " << current << " A\n";

    if (isOnline)
    {
        std::cout << "Status: ONLINE\n";
    }
    else
    {
        std::cout << "Status: OFFLINE\n";
    }

    std::cout << "Error: " << getErrorMessage() << "\n";
}

