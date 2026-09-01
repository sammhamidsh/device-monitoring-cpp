#include "DeviceManager.h"
#include <iostream>
#include <random>

void DeviceManager::addDevice(Device newDevice)
{
	devices.push_back(newDevice);
}

void DeviceManager::runDiagnosticsAll()
{
	for (int i = 0; i < devices.size(); i++)
	{
		devices[i].runDiagnostics();

		if (devices[i].getErrorCode() != NO_ERROR) 
		{
			logger.log("[ERROR] " + devices[i].getName() + " - " + devices[i].getErrorMessage());
		}
	}
}

void DeviceManager::printAllDevices()
{
	for (int i = 0; i < devices.size(); i++)
	{
		devices[i].printStatus();
	}
}

void DeviceManager::printSystemSummary()
{
	int healthyCount = 0;
	for (int i = 0; i < devices.size(); i++)
	{
		if (devices[i].getErrorCode() == NO_ERROR)
		{
			healthyCount++;
		}
	}
	int errorCount = devices.size() - healthyCount;

	std::cout << "===== SYSTEM SUMMARY =====\n";
	std::cout << "Total devices: " << devices.size() << "\n";
	std::cout << "Healthy devices: " << healthyCount << "\n";
	std::cout << "Devices with errors: " << errorCount << "\n";
}

Device* DeviceManager::findDeviceById(int id)
{
	for (int i = 0; i < devices.size(); i++)
	{
		if (devices[i].getId() == id)
		{
			return &devices[i];
		}
	}

	return nullptr;
}

void DeviceManager::simulateFault(int id, FaultType faultType)
{
	Device* device = findDeviceById(id);

	if (device != nullptr)
	{
		if (faultType == TEMPERATURE_FAULT)
		{
			device->setTemperature(100);
		}
		else if (faultType == VOLTAGE_FAULT)
		{
			device->setVoltage(1.8);
		}
		else if (faultType == CURRENT_FAULT)
		{
			device->setCurrent(5.0);
		}
		else if (faultType == OFFLINE_FAULT)
		{
			device->setIsOnline(false);
		}
	}
}

void DeviceManager::updateDeviceData(int id, double temperature, double voltage, double current, bool isOnline)
{
	Device* device = findDeviceById(id);

	if (device != nullptr)
	{
		device->setTemperature(temperature);
		device->setVoltage(voltage);
		device->setCurrent(current);
		device->setIsOnline(isOnline);
	}
}

void DeviceManager::generateSimulatedData()
{
	static std::random_device rd;
	static std::mt19937 gen(rd());

	std::uniform_real_distribution<> tempDist(60.0, 100.0);
	std::uniform_real_distribution<> voltDist(0.8, 1.6);
	std::uniform_real_distribution<> currDist(0.2, 5.0);
	std::bernoulli_distribution onlineDist(0.95);

	for (int i = 0; i < devices.size(); i++)
	{
		devices[i].setTemperature(tempDist(gen));
		devices[i].setVoltage(voltDist(gen));
		devices[i].setCurrent(currDist(gen));
		devices[i].setIsOnline(onlineDist(gen));
	}
}

