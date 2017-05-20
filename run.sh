#!/bin/bash

if [ "$1" == "DEBUG" ]
then
    echo Running DEBUG mode
    echo ******************
    valgrind --tool=memcheck --leak-check=full drop/driver.exe
else
    drop/driver.exe
fi
