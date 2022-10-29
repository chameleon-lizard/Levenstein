# Foundations of Software Engineering
Final project, Skoltech, 2022

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
How to modify project
1. xxx
