# An OpenGL Demoscene Project

Inspired by the demoscene subculture, this project implements a demo presentation using C++ and the OpenGL library for rendering. 

### What is Demoscene?

The demoscene is a computer art subculture that focuses on creating demos, real-time visual and auditory displays of artistic and technical skills. Originating from the 80s hacker culture, demosceners attempt to push the boundaries of computer graphics, animation, and music. Often, demos are optimized to run on specific hardware platforms and meet certain constraints, such as having the executable be no larger than 64kb.

## Overview

This demoscene project was designed to be accompanied by the song _Boot_, by the band _The Algorithm_ (https://www.youtube.com/watch?v=VAbm7PPYHa4).

### Prerequisites

- C++ Compiler (such as `g++`)
- OpenGL and GLUT libraries installed on your system

To install the required libraries, run the following command on your terminal application:

```bash
 sudo apt install libglew-dev freeglut3-dev libglu1-mesa-dev
```

### Compilation and Execution

To run this program, you will need to compile the C++ code and run the resulting executable. You can compile the code by using the following command to link the required libraries:

```
g++ demoscene.cpp -lGLEW -lglut -lGL -lGLU -o demo_exec
```

Then execute the program with:

```
./demo_exec
```

> [!IMPORTANT]
> To ensure that the demo runs as intended, please do not resize the application window. This happens due to limitations in the GLUT library.
