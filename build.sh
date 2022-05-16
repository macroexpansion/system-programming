#!/bin/sh

if [ -d "dist" ] 
then
    cd dist
else
    mkdir dist && cd dist
fi

cmake -DCMAKE_C_COMPILER=gcc ..
cmake --build . --config Debug
