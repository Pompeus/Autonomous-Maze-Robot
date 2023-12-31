# Autonomous Maze Robot

This repository refers to a project involving a robot navigating a maze as quickly as possible without colliding during the course.

<div style = "display: inline_bloc">
  <img align = "center" alt = "Labyrinth" src = "Images/Labyrinth.jpg" width = 600/>
  </div></br>

• **Reactive behavior:** The robot has motor control for obstacle avoidance using an ultrasonic sensor model in a mapped environment.

• **Braitenberg vehicle-type reactive behavior:** The robot either follows or moves away from one (or more) light sources while also avoiding obstacles.

• **Reactive maze-solving:** The robot must efficiently navigate a maze by avoiding obstacles and minimizing time.
  
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

O assembled prototype, upon reviewing the list of mechanical components that were presented, seems large; however, the model ended up being compact, resulting in ease of navigation through the maze. The prototype yielded positive results; in the initial tests, it experienced minor collisions with the maze walls. However, after adjusting its speed and ultrasonic sensors, the robot navigated the course with agility, with four standout performances in the tests:

• **The first:** The robot tended to lean to the left, causing its side to collide with the wall. By correcting the lateral sensors, it was possible to maintain a minimum distance for the robot to adjust its direction and move straight within the maze.

• **The second:** The robot reached the halfway point but collided due to its speed, making it unable to navigate the tighter turns of the maze. Since it was moving too quickly, it was necessary to sacrifice some speed to successfully navigate the tight corners.

• **The third:** The robot completed the entire course, entering various dead-end sections of the maze and successfully navigating out without any issues.

• **The fourth:** By adjusting minor settings in the sensor and software, the robot managed to complete the entire course in around 1:08 minutes without apparent problems.


<div style = "display: inline_bloc"></br>
  <img align = "center" alt = "Robot1" src = "Images/Robot1.jpg" width = 200/>
  <img align = "center" alt = "Robot2" src = "Images/Robot2.jpg" width = 200/>
  <img align = "center" alt = "Robot3" src = "Images/Robot3.jpg" width = 200/>
  <img align = "center" alt = "Robot4" src = "Images/Robot4.jpg" width = 200/>
  <img align = "center" alt = "Robot5" src = "Images/Robot5.jpg" width = 200/>
  <img align = "center" alt = "Robot6" src = "Images/Robot6.jpg" width = 200/>
  <img align = "center" alt = "Robot7" src = "Images/Robot7.jpg" width = 200/>
  <img align = "center" alt = "Robot8" src = "Images/Robot8.jpg" width = 200/>
  </div></br>


## Computer Vision Path Tracking System with ArUco Markers
### • Explanation of the purpose of ArUco markers
ArUco markers are widely used in computer vision and object tracking. Their main purpose is to provide easily identifiable reference points in environments that can be used to track the position and orientation of objects, such as robots, cameras, or any object equipped with ArUco markers. The markers are printed on sheets of paper, cardboard, or other materials and contain encoded information that makes them unique. Vision systems can detect, identify, and track these markers in real-time.

To generate the markers, it is necessary to use a code dictionary (e.g., DICT_4X4_50) that specifies the format of the markers and their ID, where "4x4" indicates the marker's size, which can also be 5x5 or 6x6, and "50" indicates the total number of distinct markers available in the dictionary. Marker generation is performed using computer vision libraries such as OpenCV. The software creates the markers and prints them for use in practical applications.

Marker identification occurs when a camera captures an image of the environment and detects the markers in the frame. Through image processing techniques, the software identifies the position and orientation of each marker and uses this information to perform tasks such as mapping, localization, and navigation.


### • Description of the Environment Configuration:

The configuration of the environment must be carefully planned to allow for the efficient detection of ArUco markers. The camera should be positioned to have a clear view of the markers. This involves choosing the height and angle of the camera, as well as defining the camera's field of view (FOV). The markers should be well distributed in the environment to ensure they are visible from various positions.

### • Usage/Implementation of Image Preprocessing Techniques:

To enhance the detection and identification of ArUco markers, it is common to apply image preprocessing techniques. This may include the application of filters to reduce noise in the image, segmentation to separate the markers from the background, and binarization to make the markers more visible. Lens distortion correction techniques may also be necessary depending on the camera used. Some of the techniques that would be interesting to work on in this context include:

• **Filtering:** A common preprocessing step is filtering, which aims to smooth the image and reduce noise, making the markers more visible. Applying filters such as the mean filter, Gaussian filter, or median filter helps eliminate random noise and improve the quality of the captured image.

• **Binarization:** Binarization is another relevant technique used to convert the image into a black-and-white representation, where the markers appear as white regions on a black background. This simplifies the detection of edges and contours of the markers, facilitating subsequent identification.

• **Segmentation:** Segmentation is useful for isolating the markers from the rest of the image, separating them into regions or objects of interest. This technique contributes to more precise detection, allowing the algorithm to focus exclusively on the markers, avoiding interference from other elements in the scene.

• **Distortion Correction:** In cases where the camera is subject to distortions, such as lens distortion, it is essential to correct them during preprocessing. Distortion can significantly affect the accuracy of marker detection. Therefore, distortion correction, usually based on camera calibration parameters, is an important step to ensure image fidelity.

The implementation of these preprocessing techniques is often carried out through image processing libraries such as OpenCV. The order and selection of techniques to be used may vary depending on the specific conditions of the camera, environment, and markers. Therefore, the choice and configuration of preprocessing techniques should be adjusted according to the particular scenario and may require tuning and experimentation to optimize the quality of ArUco marker detection.


<div style = "display: inline_bloc"></br>
  <img align = "center" alt = "ArUco" src = "Images/ArUco.jpg" width = 600/>
</div></br>

### •  Implementation

With the created code, the significant result obtained becomes evident, where the red line traces the robot's path through the maze in a clear and precise manner, as mentioned earlier. This visual representation of the trajectory, captured in real-time, attests to the success of using the ArUco marker to record the robot's journey. The success is twofold, as not only did the marker-based tracking system function effectively, but the robot's performance was also remarkable, successfully completing the course without causing damage to the maze walls. This achievement illustrates the effectiveness of the combination of tracking and navigation technologies used in this specific project.


<div style = "display: inline_bloc"></br>
  <img align = "center" alt = "ArUco" src = "Images/Aruco Path.jpg" width = 800/>
</div></br>
