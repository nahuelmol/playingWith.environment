@echo off

SET OUT=out/fs
SET BOOST_PATH=D:/mingw_libs/boost
SET PROJC_PATH=%~dp0

ECHO ..working in %PROJC_PATH%
ECHO ..compiling main script
c++ -I %BOOST_PATH% -o %OUT% fs.cpp 

ECHO ..executing 
cd out && fs
cd..
