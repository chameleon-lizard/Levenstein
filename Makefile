CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=src/main.cpp src/levenshtein.cpp
OBJECTS=${patsubst src/%.cpp,build/%.o,${SOURCES}}

TEST_SOURCES=src/test.cpp src/levenshtein.cpp
TEST_OBJECTS=${patsubst src/%.cpp,test_build/%.o,${TEST_SOURCES}}

EXECUTABLE=build/levenshtein
TEST=test_build/test

all: $(SOURCES) $(EXECUTABLE)

test: $(TEST_SOURCES) $(TEST)

$(TEST): $(TEST_OBJECTS)
	$(CC) $(LDFLAGS) $(TEST_OBJECTS) -o $@
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

test_build/%.o: src/%.cpp
	mkdir -p ${dir $@}
	${CC} -o $@ $< -c ${CFLAGS}

build/%.o: src/%.cpp
	 mkdir -p ${dir $@}
	 ${CC} -o $@ $< -c ${CFLAGS}

.PHONY : clean
clean:
	-rm -rf build test_build
