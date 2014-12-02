# Box Controller Software

## Building from source

The sources are compiled using the [XPCC library][xpcc], which is used for
GPIO, Communication, Processing, Build System and Serial Debugging.  
Enter the `box` directory

	$ cd /path/to/hotbox/software/box

To compile, execute:

	$ scons

To flash the binary onto the microcontroller using an AVR ISP mk2, execute:

	$ scons program


Installing XPCC
---------------

XPCC is provided as a git submodule, to use it run this in the root `hotbox/` directory:

	$ git submodule init
	$ git submodule update


###### To install the XPCC build system on OS X (tested on 10.9):

1.	Install [Homebrew][]:  
	`$ ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"`
2.	Install some dependencies:  
	`$ brew install scons python`  
	`$ pip install lxml jinja2`
3.	Install the latest version of [avr-libc][avrlibc] and avrdude using Homebrew:  
	`$ brew tap larsimmisch/avr`  
	`$ brew install avr-libc avrdude`


###### To install the XPCC build system on Linux (tested on Ubuntu 14.04 LTS):

	$ sudo apt-get update
	$ sudo apt-get install python scons python-jinja2 python-lxml \
	gcc-avr binutils-avr avr-libc avrdude


Further information on installing [the XPCC build system can be found here][xpcc-install].


[xpcc]: http://develop.xpcc.io/
[homebrew]: http://mxcl.github.com/homebrew/
[avrlibc]: https://github.com/larsimmisch/homebrew-avr
[xpcc-install]: http://develop.xpcc.io/install.html
