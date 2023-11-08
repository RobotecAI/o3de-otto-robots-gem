[![Apache License, Version 2.0][apache_shield]][apache]

# OTTO 600 and OTTO 1500 Robots Gem for Open 3D Engine (O3DE)

## A bit of context

* [Open 3D Engine](https:://o3de.org) - an open source game & simulation engine. O3DE is extendable through modules called Gems. This is one of such Gems.
* [Robot Operating System (ROS)](https://docs.ros.org/en/rolling/index.html) - an open source middleware and, de facto, standard for robotics.
* [ROS2 Gem](https://github.com/o3de/o3de-extras/tree/development/Gems/ROS2) - an open source module for O3DE that enables simulation for robotics using modern ROS.
* [OTTO Motors](https://ottomotors.com/) - OTTO Motors is Rockwell Automation's AMR division, providing autonomous mobile robots (AMRs) for material handling inside manufacturing facilities and warehouses.

## Requirements
- Any O3DE project with the [O3DE ROS2 Gem](https://github.com/o3de/o3de-extras/tree/development/Gems/ROS2) enabled.

## Description
This gem contains the following assets:
- [OTTO 1500 v2](https://ottomotors.com/1500)
- [OTTO 600](https://ottomotors.com/600)
- High and low stands for OTTO 1500 v2
- Stand for OTTO 600

Please note that links and how parts of the robots combine might not be faithful to the actual design, as it is not public. Models are simplified and do not contain e.g. 

OTTO 1500:
- Intel RealSense Cameras
- Embedded 6-axis IMU
- SICK Microscan3 (360 FOV)

OTTO 600:
- Forward facing 3D Perception Cameras
- 6-axis IMU

## OTTO 1500 v2 - two models

### OTTO1500_Basic_platform.prefab - containing the small, static platform
![](docs/images/OTTO1500_Basic_platform_front.png)
---

### OTTO1500_Lifting_platform.prefab - containing the high-lifting platform
![](docs/images/OTTO1500_Lifting_platform_front.png)
![](docs/images/OTTO1500_Lifting_platform_lift.png)
---
Movement of the platform can be manually steered using PhysX Debug Gem or controlled from code using the Pid Motor Controller Component.

## OTTO 600
### OTTO600.prefab - containing the lifting platform
![](docs/images/OTTO600_front.png)
![](docs/images/OTTO600_front_lift.png)

## O3DE 
Robots are delivered as prefabs, containing models and physics, along with the following ROS components:
- ROS2 Frame
- ROS2 Robot Control
- ROS2 Skid Steering Vehicle Model
- ROS2 Lidar Sensor
- ROS2 PID Motor Controller

## Acknowledgments

Models were created based on STL files kindly shared by OTTO Motors.

---

This work is licensed under [Apache License, Version 2.0][apache]. You may elect at your option to use the [MIT License][mit] instead. Contributions must be made under both licenses.

[apache]: https://opensource.org/licenses/Apache-2.0
[mit]: https://opensource.org/licenses/MIT
[apache_shield]: https://img.shields.io/badge/License-Apache_2.0-blue.svg
