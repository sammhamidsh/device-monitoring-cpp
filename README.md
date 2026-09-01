# C++ Device Monitoring & Diagnostics System

A C++ application that simulates a continuous device monitoring and diagnostics system.

The system continuously generates device measurements, analyzes device health, detects abnormal conditions, and records detected errors in a timestamped log file.

## Features

- Continuous monitoring loop
- Multiple device management
- Simulated sensor data generation
- Temperature monitoring
- Voltage monitoring
- Current monitoring
- Online/offline device detection
- Automatic fault detection and diagnostics
- Fault simulation for testing
- Timestamped error logging
- System health summary
- Device lookup and data updates

## Monitored Data

Each device contains:

- Device name and ID
- Temperature
- Voltage
- Current
- Online/offline status
- Error status

## Diagnostic Rules

The system currently checks:

| Parameter | Normal Condition |
|---|---|
| Temperature | ≤ 80°C |
| Voltage | 1.0V – 1.4V |
| Current | 0.5A – 3.0A |
| Device status | Online |

Possible diagnostic states:

- `NO_ERROR`
- `TEMPERATURE_ERROR`
- `VOLTAGE_ERROR`
- `CURRENT_ERROR`
- `DEVICE_OFFLINE`

## Monitoring Flow

```text
Generate simulated device data
            |
            v
     Run diagnostics
            |
            v
      Detect faults
            |
            v
 Log detected errors with timestamp
            |
            v
 Print device status and system summary
            |
            v
        Wait 1 second
            |
            v
           Repeat
```

The application uses a continuous monitoring loop, similar to the basic behavior of a monitoring service.

## Project Structure

```text
DeviceMonitoring/
├── Device.h
├── Device.cpp
├── DeviceManager.h
├── DeviceManager.cpp
├── Logger.h
├── Logger.cpp
└── DeviceMonitoring.cpp
```

### Device

Represents an individual monitored device and stores its measurements, status, and diagnostic state.

### DeviceManager

Manages multiple devices, runs diagnostics, generates simulated measurements, provides fault injection, and prints the system summary.

### Logger

Writes detected errors to `device_log.txt` together with the date and time of the event.

## Example Output

```text
====================================
       MONITORING CYCLE 8
====================================
Device: CPU
ID: 1
Temperature: 99.2183 C
Voltage: 1.20493 V
Current: 2.58575 A
Status: ONLINE
Error: Temperature Error

Device: GPU
ID: 2
Temperature: 68.1059 C
Voltage: 1.20357 V
Current: 1.35098 A
Status: ONLINE
Error: No Error

===== SYSTEM SUMMARY =====
Total devices: 2
Healthy devices: 1
Devices with errors: 1
====================================
```

## Error Logging

Detected faults are stored with timestamps:

```text
[01-09-2026 13:30:23] [ERROR] CPU - Temperature Error
[01-09-2026 13:30:23] [ERROR] CPU - Voltage Error
[01-09-2026 13:30:23] [ERROR] GPU - Current Error
```

The generated log file is excluded from Git using `.gitignore`.

## Technologies and C++ Concepts

- C++
- Object-Oriented Programming (OOP)
- Classes and objects
- Encapsulation
- Constructors
- Enums
- Pointers
- `std::vector`
- File I/O
- Random number generation
- Continuous monitoring loops
- Time and timestamps
- `std::thread`
- `std::chrono`
- Git and GitHub

## Simulation vs. Real Hardware

This project currently uses simulated measurements generated in software.

The monitoring and diagnostic architecture is designed so that the simulated data source can later be replaced by measurements obtained from real devices.

Depending on the hardware, real data could be received through interfaces such as serial communication, USB, network communication, or hardware-specific APIs, while the device management, diagnostics, and logging logic could largely remain the same.

## Build and Run

The project was developed using Microsoft Visual Studio on Windows.

1. Clone the repository.
2. Open `DeviceMonitoring.slnx` in Visual Studio.
3. Build the solution.
4. Run the application.

The program continuously generates and analyzes new device measurements once per second.

## Future Improvements

Possible extensions include:

- Real hardware/device input
- Configurable diagnostic thresholds
- Warning and critical severity levels
- Logging only state changes to reduce duplicate entries
- Log searching and filtering
- Additional device types
- Configuration files
- Unit tests
- Multithreaded device monitoring
- Network-based monitoring
- GUI/dashboard visualization
