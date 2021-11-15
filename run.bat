@echo off

SET OUT=out/fs
SET BOOST_PATH=D:/mingw_libs/boost
SET PROJC_PATH=%~dp0

ECHO ..working in %PROJC_PATH%

GOTO Main

:Fs
ECHO ..compiling fs script
c++ -I %BOOST_PATH% -o %OUT% fs.cpp 
GOTO Exe

:Main
ECHO ..compiling main script
c++ -I %BOOST_PATH% -o %OUT% main.cpp
GOTO Exe

:Exe
ECHO ..executing 
cd out && fs
cd..
