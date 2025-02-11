# Foundations of Software Engineering
Final project, 2022

## Levenstein
Levenshtein distance is a string metric used to compare two sequences. We propose the levenstein C++ program and software development.

## Quickstart 
There are 3 main steps to build and test the program.
1. Clone the repository
``` 
git clone https://github.com/chameleon-lizard/Levenstein.git
```
2. Build the program
<br />2 options to run the program: *with Docker* and *without Docker*
3. Test the program
---

**How to build the program with Docker**
1. Build Docker image 
```
sudo docker build -t docker-lev .
```  
2. Run docker and please change the strings to compare 
```
docker run docker-lev {Recursive, Iterative} string_a string_b
```
3. Run `make all` to build the program
```
make all
```
---
**How to build the program without Docker**

1. Run `make all`
```
make all
```
2. Build the program and please change the strings to compare 
```
./build/levenshtein {Recursive, Iterative} string_a string_b
```
---
**How to test the program**
<br />Run the following commands to test the program
```
make test && ./test_build/test
```

## Development
The source code is separated into three files. 
- In the `main.cpp` file, there is the code for launching application and parsing command line arguments.
- In the `levenstein.h` file, there are defines of the functions used in the library — both the naive and wagner_fisher implementation of the Levenstein Distance calculation algorythm.
- In the `levenstein.cpp` file, you can find source code for the library functions.

To add functionality to the application, you should first write a new function inside the `levenstein.cpp` file, then add the header of the function to the `levenstein.h` file. To test if it works, you may use the `main.cpp` file, add the new function call, and start working with it right away. Alternatively, you can import the `levenstein.h` library to another project and use the functions there.
