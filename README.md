# Simple snake game made in C++17 with STL

Navigation through WSAD keys.  
Keys and board size can be easily changed by modifying main.cpp

### build deps:
 - `gcc`
 - `cmake`
### additional for Windows:
- `MinGW or any GNU "make" port`


### GNU build proces:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Windows MinGW build proces:
```
$ mkdir build
$ cd build
$ cmake .. -G "MinGW Makefiles"
$ mingw32-make
```

executable is in build/bin/

Port to ncurses in work, planning major changes:
- better snake grow mechanism (growing when the apple comes to end of tail)  
- better snake move mechanism (real-time moving without clicking enter)
- better GUI

Project inspired by <a href = "https://github.com/gizlu/">gizlu</a>/<a href = "https://github.com/gizlu/snake">snake</a>. But just inspired, not copied (at least not all). I've took only random number generator, most of main.cpp and README because of same installation processes. Code is similar, but that's very simple game and almost all of these are made accidently.