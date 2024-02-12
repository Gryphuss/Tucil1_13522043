# Cyberpunk 2077 Breach Protocol Solver

## Description

A program designed to solve the Breach Protocol minigame in Cyberpunk 2077 with a brute-force algorithm. This proram allows user to enter a Breach Protocol matrix and target solution through a txt file or by the CLI, and returns the best possible sequence with maximum value possible. This program is entirely written in C++.

## Requirements

### For Windows

Make sure you have MinGW-w64 that provides the GCC compiler for windows.

1. Download and install MinGW-w64.
2. Add that the bin directory of MinGW-w64 to your system's PATH variable to access the **g++** compiler

### For Linux

Make sure you have **GCC** compiler collection installed. Usually GCC is inculded in Ubuntu, but if it's not installed you can install **g++** with the following command.

```bash
sudo apt install g++
```

## Installation

1. Clone the repository

```cmd
git clone https://github.com/Gryphuss/Tucil1_13522043.git
```

2. Navigate to bin directory

```cmd
cd Tucil1_13522043
cd bin
```

3. Execute the compiled C++ program

### Windows

```cmd
realmain.exe
```

### Linux

```cmd
./realmain
```

If you wish to compile the program, you can do it by using the following command

```cmd
cd ..
cd src
g++ -o exec_name realmain.cpp
```

## User Guide

At the very beginning of the program, it will offer 2 ways of data input:

**Manual Input**: You will be asked to input your desired number of unique tokens, the unique tokens themselves, buffer size, matrix dimensions, the amount of target sequences and their lengths. The program will then randomize the matrix and target sequences and find the maximum value buffer.  
**File Input**: Add to the test folder your file with .txt extension. Any other extension or any other directory will result the program to be faulty. The program will then find the maximum value buffer.

When the final buffer is completed the program will offer you to save your solution to a file.

## Creator

Daniel Mulia Putra Manurung - 13522043  
danielmuliaputraolo@gmail.com
