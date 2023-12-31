# Autonomous Maze Robot

This repository refers to a project involving a robot navigating a maze as quickly as possible without colliding during the course.

• Reactive behavior: The robot has motor control for obstacle avoidance using an ultrasonic sensor model in a mapped environment.

• Braitenberg vehicle-type reactive behavior: The robot either follows or moves away from one (or more) light sources while also avoiding obstacles.

• Reactive maze-solving: The robot must efficiently navigate a maze by avoiding obstacles and minimizing time.
  
The robot assembly primarily utilized components from the LEGO Kit 9790 (Mindstorms for Schools), consisting of 726 pieces.
A detailed list of kit pieces used in the robot's development.

### Mechanical Parts Table
|  **Parts** | **Quantity**| 
|-------------|-------------|
| Gray Bushing 1/2   |  6  |
| Gray Lego Bushing      | 4     |
| Axle 6L without Stop Black   | 2      |
|Gear 40 Teeth Gray | 2|
|Gear 8 Teeth Type 1 Gray| 2|
|Mini Electric Motor 9V Gray RCX 43362| 2|
|Plate 1x10 Gray| 2|
|Plate 1x2 Gray| 7|
|Plate 1x8 Gray| 2|
|Plate 2x10 Gray|3|
|Plate 2x2 Blue|4|
|Plate 2x2 Gray|2|
|Plate 2x4 Gray|4|
|Plate 2x6 Gray|4|
|Plate 2x8 Gray|5|
|Plate 6x10 Gray|2|
|Plate 6x10 Black|2|
|Round Plate 1x1 Blue|2|
|Tire 81.6x15| 4|
|Wheel 81.6x15|4|
|Brick 1x12 with 11 holes Black|4|
|Brick 1x2 with 1 hole Black|4|
|Brick 1x4 with 3 holes Black|2|
|Brick 1x8 with 7 holes Black| 9|
|Brick 2x4 Black| 2|
|Brick 2x6 Black|2|


The main locomotion of the robot was achieved through the integration of 9V electric motors of the Lego 43362 Power Motor Technic Mindstorms RCX 43362 model. 
Additionally, a ball transfer mechanism was incorporated into the front part of the robot to provide a higher degree of freedom, range of motion, and the ability to rotate 
around its own axis.

The hardware includes an Arduino ADK with an Atmel AVR microcontroller, featuring Atmega2560, 8 bits, and 16 MHz, 54 pins, 8KB RAM, 256 KB flash, and 5V.

Ultrasonic sensors of the HC-SR04 type were used to address the reactive maze-solving challenge, enabling effective obstacle detection and evasive maneuvers in the shortest 
possible time. Additionally, LDR (Light Dependent Resistor) photoresistors were incorporated to give the robot a Braitenberg vehicle-type reactive behavior, causing the robot
to flee from light sources and avoid obstacles, with the assistance of ultrasonic sensors.

The entire system was powered by a rechargeable 9V battery. A 170-point Protoboard was directly connected to the Arduino's 5V, powering all components except for the motors,
which received direct power from the battery. A toggle switch was incorporated to allow selective activation of the circuit when necessary. The motors were connected to an
H-bridge (L298N) that, through electronic switching, allows variation in the motor's rotation states. This represents a more efficient approach compared to mechanical 
switching and provides additional protection against overcurrent. A schematic of the circuit used in the robot was developed on the Tinkercad platform and can be viewed 
in Figure 2. For the connection of the photoresistors, 10kOhm resistors were used.

### Electrical Components Table
|  **Components** | **Quantity**| 
|-------------|-------------|
|Brick 2x2 Eletric Conector Black| 2|
|Arduino Mega ADK| 1|
|Battery 9V 450mAh| 1|
|Toggle Switch 2 pins| 1|
|Battery Clip 9V Black- Type 1|1|
|Plug Connector P4 Male|1|
|H-Bridge Driver L298N| 1|
|Mini Protoboard 170 points|1|
|Resistor 10K Ohm 10%|4|
|Photoresistor LDR| 4|
|Ultrasonic sensor HC-SR04| 3|
|Spherical Transfer RO53XX15XX, REXroth,7210|1|




