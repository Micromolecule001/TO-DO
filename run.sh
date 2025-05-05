#!/bin/bash
mkdir -p build
cd build
qmake ../ToDO-list.pro
make
./ToDO-list

