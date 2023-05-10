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

runTest: prebuild stack.o testStack.o mainTest.o regexTest.o regex.o char.o postfix.o util.o postfixTest.o
	$(CC) $(buildDir)/stack.o $(buildDir)/char.o $(buildDir)/util.o $(buildDir)/regex.o $(buildDir)/postfix.o $(buildDir)/testStack.o $(buildDir)/mainTest.o $(buildDir)/regexTest.o $(buildDir)/postfixTest.o -o $(buildDir)/runTest

stack.o: $(stackPath)/stack.c $(stackPath)/stack.h
	$(CC) -c $(stackPath)/stack.c -o $(buildDir)/stack.o

regex.o: $(src)/regex.c $(src)/regex.h $(src)/regex_in.h
	$(CC) -c $(src)/regex.c -o $(buildDir)/regex.o

char.o: $(src)/char.c $(src)/char.h
	$(CC) -c $(src)/char.c -o $(buildDir)/char.o

util.o: $(src)/util.c $(src)/util.h
	$(CC) -c $(src)/util.c -o $(buildDir)/util.o

postfix.o: $(src)/postfix.c $(src)/postfix.h
	$(CC) -c $(src)/postfix.c -o $(buildDir)/postfix.o


testStack.o: $(testPath)/testStack.c $(testPath)/testStack.h
	$(CC) -c $(testPath)/testStack.c -o $(buildDir)/testStack.o

regexTest.o: $(testPath)/regexTest.c $(testPath)/regexTest.h
	$(CC) -c $(testPath)/regexTest.c -o $(buildDir)/regexTest.o

postfixTest.o: $(testPath)/postfixTest.c $(testPath)/postfixTest.h
	$(CC) -c $(testPath)/postfixTest.c -o $(buildDir)/postfixTest.o


mainTest.o: $(testPath)/mainTest.c
	$(CC) -c $(testPath)/mainTest.c -o $(buildDir)/mainTest.o



clean:
	rm -rf build