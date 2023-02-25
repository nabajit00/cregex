CC=gcc
src = ./src
DSPath=./src/DS
stackPath=$(DSPath)/stack
testPath=$(src)/test
regexPath=$(src)/regex
buildDir = ./build

all:prebuild

prebuild:
	mkdir -p $(buildDir)

runTest: prebuild stack.o testStack.o mainTest.o regexTest.o regex.o
	$(CC) $(buildDir)/stack.o $(buildDir)/testStack.o $(buildDir)/mainTest.o $(buildDir)/regex.o $(buildDir)/regexTest.o -o $(buildDir)/runTest

stack.o: $(stackPath)/stack.c $(stackPath)/stack.h
	$(CC) -c $(stackPath)/stack.c -o $(buildDir)/stack.o

regex.o: $(src)/regex.c $(src)/regex.h
	$(CC) -c $(src)/regex.c -o $(buildDir)/regex.o

testStack.o: $(testPath)/testStack.c $(testPath)/testStack.h
	$(CC) -c $(testPath)/testStack.c -o $(buildDir)/testStack.o

regexTest.o: $(testPath)/regexTest.c $(testPath)/regexTest.h
	$(CC) -c $(testPath)/regexTest.c -o $(buildDir)/regexTest.o

mainTest.o: $(testPath)/mainTest.c
	$(CC) -c $(testPath)/mainTest.c -o $(buildDir)/mainTest.o



clean:
	rm -rf build