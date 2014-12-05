# HotBox

HotBox, a solution with the following properties:

1. It allows exposition of sensor motes to a wide range of temper- atures with a high degree of accuracy.
2. It supports specifying exact spatial orientation of motes which, if not ensured, interferes with repeatable experiment setups. 
3. It is reasonably easy to assemble by following the information (code, PCB schematics, hardware list and crafting instructions) available online, facilitating further use of the platforms by other researchers.

For further information have a look at the [HotBox technical report][hotbox].

## Organization

This repository is organized as follows:

- 	The *hardware* folder contains all hardware files for the box.
	-	*hardware/et* contains the PCB schematics and layouts.
	-	*hardware/baseboard* contains the vector files of all parts of the baseboard (for the lasercutter).
	-	*hardware/harness* contains the vector files of all parts of the mote harness (for the lasercutter).
- 	The *software* folder contains the software for the controller.
	- 	*software/source* contains the actual application code for this robot.
	-	*software/xpcc* contains the git submodule for the xpcc.io microcontroller framework.

All hardware and embedded software was designed by [Niklas Hauser][hauser] during his [bachelor thesis][bachelor].

[hotbox]: http://sunsite.informatik.rwth-aachen.de/Publications/AIB/2014/2014-14.pdf
[hauser]: http://www.salkinium.de
[bachelor]: https://github.com/salkinium/bachelor
