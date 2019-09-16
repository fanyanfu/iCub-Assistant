# Grasping, Walking and Navigating with an iCub
Algorithms for object manipulation and walking with the iCub as shown below:

- Reaching, Grasping and Manipulating while Balancing  
<p align="center">
<img src="https://github.com/epfl-lasa/iCub-Assistant/blob/master/doc/Sec2-VOTracking.gif"  width="400"></>
  <img src="https://github.com/epfl-lasa/kuka-lpvds-tasks/blob/master/img/inspection-exec.gif"  width="400"></>
</p> 

- Compliant and Adaptive Walk-to-Grasp and Guided Walking
<p align="center">
<img src="https://github.com/epfl-lasa/iCub-Assistant/blob/master/doc/Sec3-WalkToGrasp.gif"  width="400"></>
  <img src="https://github.com/epfl-lasa/iCub-Assistant/blob/master/doc/Sec3-WalkToGrasp-moving.gif"  width="400"></>
</p>

- Adaptive Navigation with Non-Linear DS Learned from Demonstrations
<p align="center">
<img src="https://github.com/epfl-lasa/iCub-Assistant/blob/master/doc/Sec3-WalkToGrasp.gif"  width="400"></>
  <img src="https://github.com/epfl-lasa/kuka-lpvds-tasks/blob/master/img/inspection-exec.gif"  width="400"></>
</p>

**Reference**   
Figueroa, N., Faraji, S., Koptev, M. and Billard, A. (2019) "A Dynamical System Approach for Adaptive Grasping, Navigation and Co-Manipulation with Humanoid Robots". Submitted to ICRA-2020. 

**Contact**: For questions on the methods and/or implementation contact [Nadia Figueroa](http://lasa.epfl.ch/people/member.php?SCIPER=238387) (nadia.figueroafernandez AT epfl dot ch) and [Salman Faraji](https://salmanfaraji.github.io/) (salman.faraji AT epfl dot ch)

**Acknowledgments**
This work was supported by the European Community Horizon 2020 Research and Innovation pro-
gramme ICT-23-2014, grant agreement 644727-[Cogimon](https://cogimon.eu/cognitive-interaction-motion-cogimon) and
643950-[SecondHands](https://secondhands.eu/).


## System Requirements
This code has been extensively tested on Ubuntu 16. It has been experimentally tested on Ubuntu 18 and Mac OS-X, yet we do not ensure proper execution.  
- OS: Ubuntu 16
- Yarp: Install from [yarp-link](https://www.yarp.it/install_yarp_linux.html#install_on_linux). If using ubuntu 16, get the xenial version in their repository. Make sure you enable the plugins if compiling it from the source.
- Gazebo: Install from [gazebo-link](http://gazebosim.org/tutorials?tut=install_ubuntu&ver=5.0) Version 7 or 9 work properly.

## Build Instructions 
Within the `~./iCub-Assistant/` folder:
- Go to `~./iCub-Assistant/gazebo-yarp-plugins/` folder and install it. Compared to the official package, this copy has two additional plugins that read robot and object positions.

```bash
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/
sudo make install
```

- Put this path in `~/.bashrc`:

```bash
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/usr/local/lib
```

- Also put the path of gazebo/objects and gazebo/robots in `~/.bashrc`. For example:

```bash
if [ -z "$GAZEBO_MODEL_PATH" ]; then
    export GAZEBO_MODEL_PATH=/home/sfaraji/Dropbox/LASA/gazebo/objects:/home/sfaraji/Dropbox/LASA/gazebo/robots
else
    export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:/home/sfaraji/Dropbox/LASA/gazebo/objects:/home/sfaraji/Dropbox/LASA/gazebo/robots
fi
```

- Install controller dependencies. Open another window, go to `~./iCub-Assistant/dependencies/collision/to_install` folder, unzip each package, navigate to each corresponding folder and:

```bash
mkdir build
cd build
cmake ..
sudo make install
```

- Install the main whole-body controller code. Go to `~./iCub-Assistant/sim/` (for simulated robot) and `~./iCub-Assistant/real/` (for real robot)  folder, and compile the code:

```bash
mkdir build
cd build
cmake ..
make -j
```


## Running Instructions 
The code works for both Gazebo simulation and experiments with the real robot. 
- In one command window run:

```bash
yarpserver
```

- [For Gazebo simulation] Open another window, navigate to `~./iCub-Assistant/gazebo/worlds` folder, and run:

```bash
gazebo -s libgazebo_yarp_clock.so simple.world
```

- In another window, go to either `~./iCub-Assistant/sim/` or `~./iCub-Assistant/real/` and run the controller by:

```bash
./main --robot icubSim
```

- Play with keyboard to move the hands (see `main.cpp`) or walk. The robot tracks the object whenever it is reachable.

- If you have two robots, open another window and run:

```bash
./main --robot icubSim2
```

- For real-world experiments, each controller must run individual laptops with the name of the robot being `icub`
