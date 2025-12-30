# Wifi-Based-Bot-for-Industrial-Applications
B-tech Final Year Project

Below is a **clean, GitHub-ready README.md** tailored from your project report, structured for academic + recruiter visibility, and concise enough for repositories.

---

# 📡 Wi-Fi Based Bot for Industrial Applications

A **Wi-Fi controlled robotic bot** designed for **remote industrial operations**, enabling real-time **speed and direction control of DC motors** via a web interface using the **ESP8266 (ESP-12F)** microcontroller.

---

## 📌 Project Overview

This project implements a **browser-based control system** for a mobile robotic platform using **PWM-based DC motor speed control**. The bot operates over a local Wi-Fi network and can be accessed from **any device with a web browser**, making it suitable for **industrial automation, monitoring, and remote handling applications**.

---

## ⚙️ System Architecture

**Client (Web Browser)**
⬇ HTTP Requests
**ESP8266 (ESP-12F) – Wi-Fi Server**
⬇ PWM + Direction Signals
**L298N Dual H-Bridge Motor Driver**
⬇
**DC Motors (Bot Wheels)**

---

## 🧩 Key Features

* 🌐 **Wi-Fi based remote control** (no Bluetooth / IR limitations)
* 🧭 **Bidirectional motor control** (Forward, Reverse, Left, Right)
* 🎚️ **Smooth speed control using PWM**
* 🖥️ **Web-based UI (HTML + CSS)** — no mobile app required
* 🔋 **On-board battery with 3-cell BMS**
* 🔄 **Scalable architecture** for multiple bots on same router

---

## 🛠️ Hardware Components

| Component         | Description                        |
| ----------------- | ---------------------------------- |
| ESP-12F (ESP8266) | Wi-Fi enabled microcontroller      |
| L298N             | Dual H-Bridge motor driver         |
| DC Motors         | Differential drive                 |
| Li-ion Batteries  | 3 × 3.7 V (12 V total)             |
| 3-Cell BMS        | Battery protection                 |
| FTDI Module       | Programming & serial communication |
| Servo Motor       | Load drop mechanism                |
| Custom Chassis    | Wooden base                        |

---

## 💻 Software Stack

* **Arduino IDE**
* **ESP8266WiFi Library**
* **Embedded HTML + CSS**
* **PWM Motor Control Logic**

---

## 🔁 Working Principle

* ESP8266 connects to a Wi-Fi router in **Station Mode**
* Acts as a **local web server**
* User sends commands via webpage buttons
* ESP8266 converts commands to **PWM duty cycles**
* L298N controls motor speed and direction accordingly

---

## 📊 Results

* ✔ Smooth and stable motion control
* ✔ Accurate PWM-based speed variation
* ✔ Reliable Wi-Fi communication
* ✔ Real-time response via browser interface
* ✔ Modular and extendable design

---

## 🏭 Industrial Use Cases

* **Remote industrial automation**
* **Material transport bots**
* **Hazardous environment monitoring**
* **Warehouse logistics**
* **Surveillance & inspection**
* **Environmental monitoring**
* **Swarm robotics (future scope)**

---

## 🚀 Future Enhancements

* Obstacle detection (Ultrasonic / LiDAR)
* Camera-based surveillance
* Autonomous navigation
* AI/ML-based decision making
* Multi-bot coordination (swarm robotics)
* Cloud & IoT dashboard integration

---

## 👨‍💻 Authors

* **Aryan Mukherjee**
* Soumyajit Sen
* Onkita Saha
* Sayan Ghosh

**Supervisor:** Dr. Subhashis Maitra
**Department:** Electronics & Communication Engineering
**Institute:** Kalyani Government Engineering College

---



