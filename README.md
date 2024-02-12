# Cyberpunk 2077 Breach Protocol Solver

## Description

A program designed to solve the Breach Protocol minigame in Cyberpunk 2077 with a brute-force algorithm. This proram allows user to enter a Breach Protocol matrix and target solution through a txt file or by the CLI, and returns the best possible sequence with maximum value possible. This program is entirely written in C++.

## Requirements

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
./realmain.exe
```

or

```cmd
realmain.exe
```

### Linux

```cmd
./realmain
```

## User Guide

At the very beginning of the program, it will offer 2 ways of data input:

**Manual Input**: You will be asked to input your desired number of unique tokens, the unique tokens themselves, buffer size, matrix dimensions, the amount of target sequences and their lengths. The program will then randomize the matrix and target sequences and find the maximum value buffer.
**File Input**: Add to the test folder your file with .txt extension. Any other extension or any other directory will result the program to be faulty. The program will then find the maximum value buffer.

When the final buffer is completed the program will offer you to save your solution to a file.

## Creator

Daniel Mulia Putra Manurung
danielmuliaputraolo@gmail.com
