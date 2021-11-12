## playingWith.environment
Here I have a problem with filesystem's header system management, then I have decide to add a .hpp file to my include folder. Thanks for https://github.com/gulrak/filesystem

* It must be executed `cmake -G "MinGW Makefiles"` in cmd or promt for setting mingw as generator
* I have added few .dll libraries for execute `make .` correctly in my system

Let me tell you what I did..

Type in cmd `cmake .` to make Makefile and after `make`, it maybe trow you a `ld` (link) error like to me. Later, utilize `make demo` for building `demo.exe` diectly. Finally, just execute `demo.exe`
