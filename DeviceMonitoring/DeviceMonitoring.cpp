#include <iostream>
#include "Device.h"
#include "DeviceManager.h"
#include <thread>
#include <chrono>

int main()
{
    DeviceManager manager;

    Device cpu("CPU", 1);

    cpu.setTemperature(75.5);
    cpu.setVoltage(1.2);
    cpu.setCurrent(2.5);
    cpu.setIsOnline(true);

    manager.addDevice(cpu);

    Device gpu("GPU", 2);
    
    gpu.setTemperature(72.0);
    gpu.setVoltage(1.3);
    gpu.setCurrent(2.8);
    gpu.setIsOnline(true);

    manager.addDevice(gpu);

   int cycle = 1;
   while(true)
   {
       std::cout << "\n====================================\n";
       std::cout << "       MONITORING CYCLE " << cycle << "\n";
       std::cout << "====================================\n";

       manager.generateSimulatedData();

       manager.runDiagnosticsAll();
       manager.printAllDevices();
       manager.printSystemSummary();

       std::cout << "====================================\n\n";

       cycle++;

       std::this_thread::sleep_for(std::chrono::seconds(1));
   }

    return 0;
}