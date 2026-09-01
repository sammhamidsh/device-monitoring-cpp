#pragma once
#include <string>

enum ErrorCode
{
	NO_ERROR,
	TEMPERATURE_ERROR,
	VOLTAGE_ERROR,
	CURRENT_ERROR,
	DEVICE_OFFLINE
};
class Device
{
private:
	std::string name;
	int id;

	double temperature;
	double voltage;
	double current;

	bool isOnline;
	ErrorCode errorCode;

public:
	Device(std::string deviceName, int deviceId);
	std::string getName();
	int getId();
	void setTemperature(double newTemp);
	double getTemperature();
	void setVoltage(double newVolt);
	double getVoltage();
	void setCurrent(double newCurr);
	double getCurrent();
	void setIsOnline(bool newStatus);
	bool getIsOnline();
	ErrorCode getErrorCode();
	bool isTemperatureHigh();
	bool isVoltageNormal();
	bool isCurrentNormal();
	std::string getErrorMessage();
	void runDiagnostics();
	void printStatus();
};