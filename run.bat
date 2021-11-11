@echo off

SET OUT=out/out
SET LIBPATH=D:/mingw_libs/boost

ECHO ..compiling main script
c++ -I %LIBPATH% -o %OUT% main.cpp 

ECHO ..executing 
cd out && out 
cd..