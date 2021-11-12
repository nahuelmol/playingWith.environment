@echo off

SET OUT=out/out
SET BOOST_PATH=D:/mingw_libs/boost
SET PROJC_PATH=""

ECHO ..compiling main script
c++ -I %LIBPATH% %PROJC_PATH% -o %OUT% main.cpp 

ECHO ..executing 
cd out && out 
cd..
