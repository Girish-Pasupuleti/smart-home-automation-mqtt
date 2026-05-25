# 🏠 Voice Controlled Smart Home Automation using MQTT Protocol

## 📌 Project Overview

The **Voice Controlled Smart Home Automation System** is an Internet of Things (IoT)-based embedded project designed to automate household appliances through voice commands and a mobile application interface.

This system uses the **MQTT (Message Queuing Telemetry Transport) protocol** for lightweight, fast, and reliable communication between the mobile application and the ESP32 microcontroller over Wi-Fi.

The project enables real-time control of multiple home appliances including:

- 💡 Bedroom Light
- 💡 Hall Light
- 🌪️ DC Fan

Users can control these appliances through voice commands using a dedicated mobile application, creating a smart, efficient, and user-friendly home automation environment.

This project demonstrates practical implementation of:

- Embedded Systems Design
- Internet of Things (IoT)
- MQTT Communication Protocol
- ESP32 Wireless Communication
- Relay-based Appliance Control
- Voice Command Processing
- Mobile App Integration

---

# 🎯 Project Objectives

The main objectives of this project are:

- To design a smart home automation system using IoT technology
- To control household appliances using voice commands
- To establish real-time communication using MQTT protocol
- To create a user-friendly mobile application interface
- To reduce manual effort in controlling home appliances
- To develop a scalable architecture for future smart home expansion

---

# 🚀 Features

### Core Features
✔ Voice-controlled appliance switching  
✔ Real-time MQTT communication  
✔ Wireless control over Wi-Fi  
✔ Mobile application integration  
✔ Control of multiple appliances  
✔ Lightweight communication protocol  
✔ Fast response time  
✔ Low power embedded implementation  

### Controlled Appliances
This project currently controls:

| Appliance | Function |
|---------|----------|
| Bedroom Light | ON / OFF |
| Hall Light | ON / OFF |
| DC Fan | ON / OFF |

---

# 🛠 Technologies Used

## Hardware
- ESP32 Development Board
- Relay Module
- DC Fan
- LED Bulbs / Lights
- Breadboard
- Jumper Wires
- Power Supply
- Wi-Fi Router

## Software
- Arduino IDE
- MQTT Broker (HiveMQ / Mosquitto)
- Mobile Application
- Embedded C / Arduino Programming

## Communication Protocol
- MQTT Protocol

---

# 📡 About MQTT Protocol

MQTT (Message Queuing Telemetry Transport) is a lightweight messaging protocol designed for IoT communication.

It follows a **publish-subscribe model**, making it ideal for smart home automation applications where low bandwidth and fast communication are essential.

### Why MQTT?
- Lightweight protocol
- Low latency
- Fast communication
- Reliable message delivery
- Ideal for IoT devices
- Supports scalable smart home architecture

### MQTT Workflow
1. Mobile app publishes appliance control commands
2. MQTT broker receives the commands
3. ESP32 subscribes to relevant MQTT topics
4. ESP32 processes received commands
5. Relay module switches appliances accordingly

---

# 🏗 System Architecture

## Overall Architecture Flow

```text
User Voice Command
        ↓
Mobile Application
        ↓
Speech Recognition Processing
        ↓
MQTT Publish Command
        ↓
MQTT Broker
        ↓
ESP32 MQTT Subscriber
        ↓
Command Processing
        ↓
Relay Module Control
        ↓
Bedroom Light / Hall Light / DC Fan