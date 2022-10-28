# Foundations of Software Engineering
Final project, Skoltech, 2022

## Levenstein
Levenshtein distance is a string metric used to compare two sequences. We propose the levenstein C++ program and software development.

## Quickstart 
How to build the program
1. Clone the repository 
``` 
git clone https://github.com/chameleon-lizard/Levenstein.git
```
2. Build Docker image 
```
sudo docker build -t docker-lev .
```  
3. Run docker
```
sudo docker run docker-lev Recursive abc abc
```
4. Run `make all` to build the program, and to run tests, use `make test && ./test_build/test`
```
make all
make test && ./test_build/test
```

## Development
How to modify project
1. 
