# Using SITL with Webots

[Webots](https://www.cyberbotics.com/#webots "Webots") is an open source robot simulator that provides a complete development environment to model, program and simulate robots. Thousands of institutions worldwide use it for R&D and teaching. Webots has been codeveloped by the Swiss Federal Institute of Technology in Lausanne, thoroughly tested, well documented and continuously maintained since 1996.


#### Installing Webots

Please check this [page](https://www.cyberbotics.com/download "page"). The steps is very easy and straight forward.

#### Running Simulator

1- open webots and open file libraries/SITL/examples/Webots/worlds/webots_quadPlus.wbt 
2- press "run" button.
3- run  ./libraries/SITL/examples/Webots/dronePlus.sh 

please note that to re-run the simulator you need to stop ardupilot SITL then stop webots simulator "stop button". then press "run" button on webots and then rerun ardupilot SITL.

#### Simulation using Map Street 

You can use [OpenStreetMaps](https://www.openstreetmap.org/ "OpenStreetMaps") with [Webots](https://cyberbotics.com/doc/automobile/openstreetmap-importer "Webots"), it is fairly straight forward. This is a very nice sample  **./libraries/SITL/examples/Webots/worlds/pyramids_droneX.wbt**, and you need to run SITL using **./libraries/SITL/examples/Webots/pyramids_droneX.sh**
[![Watch the video] Flying at Giza Pyramids](https://www.youtube.com/embed/c5CJaRH9Pig)

