# Foundations of Software Engineering
Final project, Skoltech, 2022

## Levenstein
Levenshtein distance is a string metric used to compare two sequences. We propose the levenstein C++ program and software development.

## Quickstart 
Let start with cloning the repository 
``` 
git clone https://github.com/chameleon-lizard/Levenstein.git
```
**How to build the program with Docker**
1. Build Docker image 
```
sudo docker build -t docker-lev .
```  
2. Run docker and please change the strings to compare 
```
docker run docker-lev {Recursive, Iterative} string_a string_b
```
3. Run `make all` to build the program, and to run tests, use `make test && ./test_build/test`
```
make all
make test && ./test_build/test
```
**How to build the program without Docker**
1. Run `make all`
```
make all
```
3. Build the program
```
./build/levenshtein {Recursive, Iterative} string_a string_b
```



## Development
How to modify project
1. xxx
