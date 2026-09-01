#pragma once

#include "Logger.h"
#include <vector>
#include "Device.h"

enum FaultType
{
    TEMPERATURE_FAULT,
    VOLTAGE_FAULT,
    CURRENT_FAULT,
    OFFLINE_FAULT
};

class DeviceManager
{
private:
    std::vector<Device> devices;
    Logger logger;

public:
    void addDevice(Device newDevice);
    void runDiagnosticsAll();
    void printAllDevices();
    void printSystemSummary();
    Device* findDeviceById(int id);
    void simulateFault(int id, FaultType faultType);
    void updateDeviceData(int id, double temperature, double voltage, double current, bool isOnline);
    void generateSimulatedData();
};