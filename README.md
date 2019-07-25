# Walking
Algorithms for walking and object manipulation with iCub

-- Get yarp from here. https://www.yarp.it/install_yarp_linux.html#install_on_linux ,
If using ubuntu 16, get the xenial version in their repository. Make sure you enable the plugins if compiling it from the source.

-- Go to gazebo-yarp-plugins folder and install it. Compared to the official package, this copy has two additional plugins that read robot and object positions.

```bash
mkdir build
cd build
cmake .. -DCMAKE_INSTALL_PREFIX=/usr/local/
sudo make install
```

-- Put this path in ~/.bashrc:

```bash
export GAZEBO_PLUGIN_PATH=${GAZEBO_PLUGIN_PATH}:/usr/local/lib
```

-- Also put the path of gazebo/objects and gazebo/robots in ~/.bashrc. For example:

```bash
if [ -z "$GAZEBO_MODEL_PATH" ]; then
    export GAZEBO_MODEL_PATH=/home/sfaraji/Dropbox/LASA/gazebo/objects:/home/sfaraji/Dropbox/LASA/gazebo/robots
else
    export GAZEBO_MODEL_PATH=${GAZEBO_MODEL_PATH}:/home/sfaraji/Dropbox/LASA/gazebo/objects:/home/sfaraji/Dropbox/LASA/gazebo/robots
fi
```

-- In one command window run:

```bash
yarpserver
```

-- Open another window, navigate to gazebo/worlds folder, and run:

```bash
gazebo -s libgazebo_yarp_clock.so simple.world
```


-- Install controller dependencies. Open another window, go to dependencies/collision/to_install folder, unzip each package, navigate to each corresponding folder and:

```bash
mkdir build
cd build
cmake ..
sudo make install
```

-- Open another window, go to sim/ folder, and compile the code:

```bash
mkdir build
cd build
cmake ..
make -j
```

-- Run the controller by:

```bash
./main --robot icubSim
```

-- Play with keyboard to move the hands (see main.cpp) or walk. The robot tracks the object whenever it is reachable.

-- If you have two robots, open another window and run:

```bash
./main --robot icubSim2
```