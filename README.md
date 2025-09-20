# Sensor Mapping Robot

This is my **3rd Year MEng Individual Project** at the University of Manchester, supervised by Dr. Frank Podd.  

The project integrates **RPLIDAR A1, Raspberry Pi 4, Arduino motor control, and ROS Noetic with Hector SLAM** to achieve real-time indoor mapping and robot navigation.

---

## 🔑 Features
- Real-time **Hector SLAM mapping** using RPLIDAR A1.
- **Raspberry Pi 4** running ROS Noetic for SLAM data handling.
- **Arduino-based motor control** (front-wheel drive with PWM speed tuning).
- Headless operation: remote SSH and RViz visualization on an Ubuntu VM.
- Maps exported for further analysis and experimentation.

---

## 🛠️ Hardware & Software
- **Hardware**: Raspberry Pi 4B, Arduino Uno, RPLIDAR A1, L298N motor driver, DC motors, custom chassis.  
- **Software**: ROS Noetic, Hector SLAM, RViz, Arduino IDE (C++), Ubuntu 20.04 VM, VS Code SSH.

---

## 📷 Demo
**Robot Setup**
<img width="2000" height="1125" alt="image" src="https://github.com/user-attachments/assets/ff3bdd82-69b5-47a0-ab1f-7eae7098b54a" />

**RViz Map Outputs**

<img width="849" height="800" alt="image" src="https://github.com/user-attachments/assets/23e54175-a437-4292-8f8a-e452e4c20d23" />
<img width="850" height="800" alt="image" src="https://github.com/user-attachments/assets/5f444784-5e54-46ad-aeae-14963b56e5b9" />
<img width="813" height="799" alt="image" src="https://github.com/user-attachments/assets/8843bec5-8989-4120-8845-10e5ff03e71a" />

---

## 🚀 How to Run
1. Clone this repo:
   ```bash
   git clone https://github.com/Ketchup3013/Sensor-mapping-robot.git
   ```

3. Launch RPLIDAR on Raspberry Pi:
   ```bash
   roslaunch rplidar_ros rplidar.launch
   ```

4. Run Hector SLAM on Ubuntu VM:
   ```bash
   roslaunch hector_slam_launch tutorial.launch
   ```
