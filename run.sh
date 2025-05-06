#!/bin/bash
cd build
qmake ../NoteApp.pro
make
./NoteApp
