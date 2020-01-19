# Filler 
![FILLER](https://github.com/EmbodimentEvil/Filler/blob/master/images/icon.png)
---
##### Filler is a School 42 project. The purpose of this project is to create bot for map-filler puzzle game.
---
#### How  to clone?

`git clone --recursive https://github.com/EmbodimentEvil/Filler`
---
#### How  build?

`make re`
---
#### How to run?
There are resources that are provided by task — a virtual machine (filler_vm), maps, and bots. They are located at the resources directory.
The virtual machine moderates a game. It needs a map file and bots.
The purpose of the project is to create own bot.
A name of the created bot is sleonia.filler. It will be created after make command and placed at the root of the directory.
You can run the virtual machine with the following command:
`./resources/filler_vm -p1 ./sleonia.filler -p2 resources/players/carli.filler -f resources/maps/map01`
---
### Visualization
`./resources/filler_vm -p1 resources/players/superjeannot.filler -p2 ./sleonia.filler -f resources/maps/map02 | ./visualization/vs`
![Screen 1](https://github.com/EmbodimentEvil/Filler/blob/master/images/screen1.png)
![Screen 2](https://github.com/EmbodimentEvil/Filler/blob/master/images/screen2.png)

